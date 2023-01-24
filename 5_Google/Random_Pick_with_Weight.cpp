#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> wt;
public:
    Solution(vector<int>& w) {
        wt.push_back(w[0]);
        for(int i=1;i<w.size();i++){
            wt.push_back(wt.back()+w[i]);
        }
    }
    
    int pickIndex() {
        int rd=rand()%wt.back();
        return upper_bound(begin(wt),end(wt),rd)-begin(wt);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */



#define fr(i,num) for(int i=0;i<num;i++)
int main(){
    int num;
    cout<<"Enter number of element in an array:- ";
    cin>>num;
    vector<int>  vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
    Solution obj(vec);
}