#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int mod=(int)1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        long long peopleKonwSec=0; 
        for(int i=2;i<=n;i++){
            long long currSec=dp[max(i-delay,0)];
            long long forgerSec=dp[max(i-forget,0)];
            peopleKonwSec=((peopleKonwSec+currSec)%mod-forgerSec+mod)%mod;
            dp[i]=peopleKonwSec;
        }

        long long ans=0;
        for(int i=n-forget+1;i<=n;i++){
            ans=(ans+dp[i]+mod)%mod;
        }

        return ans;
    }
};

#define fr(i,num) for(int i=0;i<num;i++)

int main(){
    int num;
    cout<<"Enter number:- ";
    cin>>num;
    int delay,forget;
    cout<<"Enter delay and forget:- ";
    cin>>delay>>forget;

    Solution obj;
    cout<<obj.peopleAwareOfSecret(num,delay,forget);

}