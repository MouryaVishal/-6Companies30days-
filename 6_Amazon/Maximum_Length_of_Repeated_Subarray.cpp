#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)

class Solution {
    int ans=0;
    int func(int i,int j,vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &dp){
        if(i==nums1.size() || j==nums2.size()) return 0;

        if(dp[i][j]!=-1)return dp[i][j];
        int curr=0;
        if(nums1[i]==nums2[j]){
            curr=1+func(i+1,j+1,nums1,nums2,dp);
        }
        ans=max(curr,ans);
        func(i,j+1,nums1,nums2,dp);
        func(i+1,j,nums1,nums2,dp);

        return dp[i][j]=curr;
    }
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(1001,vector<int>(1001,-1));
        func(0,0,nums1,nums2,dp);
        return ans;
    }
};


int main(){
    int num;
    cout<<"Enter number of element in an array:- ";
    cin>>num;
    vector<int>  vec;
    fr(i,num){
        int x;
        cin>>x;
        vec.push_back(x);
    }
    vector<int>  vec1;
    fr(i,num){
        int x;
        cin>>x;
        vec1.push_back(x);
    }
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
    Solution obj;
    cout<<obj.findLength(vec,vec1);
}