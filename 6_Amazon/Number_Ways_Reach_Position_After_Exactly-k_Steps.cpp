#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)
class Solution {
    int mod=1e9+7;
    int func(int s,int e,int k,vector<vector<int>> &dp){
        if(s==e && k==0)return 1;
        if(k==0)return 0;

        if(dp[s+1000][k]!=-1) return dp[s+1000][k];

        return dp[s+1000][k]=(int)(func(s-1,e,k-1,dp)%mod+func(s+1,e,k-1,dp)%mod)%mod;
    }
public:
    int numberOfWays(int s, int e, int k) {
        vector<vector<int>> dp(3001,vector<int>(1001,-1));
        return func(s,e,k,dp);
    }
};

int main(){
    int s,e,k;
    cout<<"Enter start , end and steps:- ";
    cin>>s>>e>>k;
    vector<int>  vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
    Solution obj;
    cout<<obj.numberOfWays(s,e,k)<<endl;
}