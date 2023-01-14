#include<bits/stdc++.h>
using namespace std;

class Solution {
    long dp[33];
    int solve(int n){
        double p=log2(n);
        if(p==(int)p) return dp[(int)p];
        p=floor((int)p);

        int ans=dp[(int)p];

        int lowestNumber=1<<(int)p;
        int left=n-lowestNumber;

        if(left>=lowestNumber/2){
            ans+=dp[(int)p-1]+(left-lowestNumber/2+1);
        }else ans+=solve(left);

        return ans;

    }
    
public:
    int findIntegers(int n) {
        dp[0]=0;
        dp[1]=0;
        int val=1;
        for(int i=2;i<33;i++){
            dp[i]=dp[i-1]+dp[i-2]+val;
            val=val<<1;
        }
        int consOne=solve(n);
        return n-consOne+1;
    }
};



#define fr(i,num) for(int i=0;i<num;i++)
int main(){
    cout<<"Enter a number:- ";
    int num;
    cin>>num;
    Solution obj;
    cout<<obj.findIntegers(num);
}