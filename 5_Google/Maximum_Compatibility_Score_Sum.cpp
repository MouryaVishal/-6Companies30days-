#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int ans = 0;
        vector<int> pos;
        for(int i=0;i<students.size();i++) pos.push_back(i);
        do{
            int curr = 0;
            for(int i = 0;i<students.size(); i++)
                for(int j=0;j<students[pos[i]].size();j++)
                    curr += (students[pos[i]][j] == mentors[i][j]);
            ans = max(ans, curr);
        } while(next_permutation(pos.begin(), pos.end()) );
        return ans;
    }
};

#define fr(i,num) for(int i=0;i<num;i++)
int main(){
    int num;
    cout<<"Enter number of students:- ";
    cin>>num;
    vector<int>  vec;
    vector<string> svec;
    
    vector<vector<int>> dvec;
    vector<vector<int>> dvec1;

    fr(i,num){
        vector<int>  vec;
        fr(j,num){
            int x;
            cin>>x;
            vec.push_back(x);
        }
        dvec.push_back(vec);
    }

    cout<<"NUmber of mentors:- ";
    int men;
    cin>>men;
    fr(i,men){
        vector<int>  vec;
        fr(j,men){
            int x;
            cin>>x;
            vec.push_back(x);
        }
        dvec1.push_back(vec);
    }
    vector<vector<string>> sdvec;
    Solution obj;
    cout<<obj.maxCompatibilitySum(dvec,dvec1);
}