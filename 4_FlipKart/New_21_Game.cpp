#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)

class Solution {
public:
    double new21Game(int N, int k, int maxPts) {
        if (k == 0 || N >= k + maxPts) return 1.0;
        vector<double> dp(N + 1);
        dp[0] = 1.0;
        double Wsum = 1.0, ans = 0.0;
        for (int i = 1; i <= N; ++i) {
            dp[i] = Wsum / maxPts;
            if (i < k) Wsum += dp[i]; 
            else ans += dp[i];
            if (i - maxPts >= 0) Wsum -= dp[i - maxPts];
        }
        return ans;
    }
};


int main(){
    int num,k,maxi;
    cout<<"Enter number of num , k ans maxipoint:- ";
    cin>>num>>k>>maxi;
    vector<int>  vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
    Solution obj;
    cout<<obj.new21Game(num,k,maxi);
}