#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& s) {
        sort(begin(s),end(s));

        int maxi=s[0]-bottom;
        for(int i=0;i<s.size()-1;i++){
            maxi=max(maxi,s[i+1]-s[i]-1);
        }
        maxi=max(maxi,top-s[s.size()-1]);

        return maxi;
    }
};

int main(){
    int num,top;
    cout<<"Enter bottom and top:- ";
    cin>>num>>top;
    int n;
    cout<<"number of special floors:- ";
    cin>>n;
    vector<int>  vec;
    fr(i,num){
        int x;
        cin>>x;
        vec.push_back(x);
    }
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
    Solution obj;

    cout<<obj.maxConsecutive(num,top,vec);
}