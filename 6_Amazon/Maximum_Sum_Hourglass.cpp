#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)

class Solution {
public:
    int maxSum(vector<vector<int>>& g) {
        int m=g.size();
        int n=g[0].size();
        int ans=0;
        for (int i = 0; i < m - 2; ++i) {
            for (int j = 0; j < n - 2; ++j)
            ans = max(ans, 
                g[i + 0][j] + g[i + 0][j + 1] + g[i + 0][j + 2] +
                              g[i + 1][j + 1] +
                g[i + 2][j] + g[i + 2][j + 1] + g[i + 2][j + 2]);
        }
        return ans;
    }
};

int main(){
    int r,c;
    cout<<"Enter number row and col:- ";
    cin>>r>>c;
    
    vector<string> svec;
    vector<vector<int>> dvec;
    fr(i,r){
        vector<int>  vec;
        fr(j,c){
            int x;
            cin>>x;
            vec.push_back(x);
        }
        dvec.push_back(vec);
    }
    vector<vector<string>> sdvec;
    Solution obj;
    cout<<obj.maxSum(dvec);
}