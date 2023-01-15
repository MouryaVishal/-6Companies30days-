#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
        int n=d.size();
        int m=d[0].size();
        vector<vector<int>> dp(n,vector<int>(m));

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1) dp[i][j]=min(0,d[i][j]);
                else if(i==n-1) dp[i][j]=min(0,d[i][j]+dp[i][j+1]);
                else if(j==m-1) dp[i][j]=min(0,d[i][j]+dp[i+1][j]);
                else  dp[i][j]=min(0,d[i][j]+max(dp[i][j+1],dp[i+1][j]));
            }
        }

        return abs(dp[0][0])+1;
    }
};

#define fr(i,num) for(int i=0;i<num;i++)
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> vec(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>vec[i][j];
        }
    }
    Solution obj;
    cout<<obj.calculateMinimumHP(vec);
}