#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool func(int st,int currSum,int k,int req,vector<int>&vis,vector<int>& nums){
        if(k==1)return true;
        if(st>=nums.size()){
            return false;
        }
        if(currSum==req)return func(0,0,k-1,req,vis,nums);

        for(int i=st;i<nums.size();i++){
            if(vis[i]|| nums[i]+currSum>req)continue;
            vis[i]=true;
            if(func(i+1,currSum+nums[i],k,req,vis,nums)){
                return true;
            }
            vis[i]=false;
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=accumulate(begin(nums),end(nums),0);
        if(sum%k) return false;
        int req=sum/k;
        sort(begin(nums),end(nums),greater<int>());
        vector<int> vis(nums.size(),0);

        return func(0,0,k,req,vis,nums);
    }
};

#define fr(i,num) for(int i=0;i<num;i++)
int main(){
    int k;
    cout<<"Enter value of k:- ";
    cin>>k;
    vector<int> vec;
    int num;
    cout<<"Enter number of elements in array:- ";
    cin>>num;
    fr(i,num){
        int x;
        cin>>x;
        vec.push_back(x);
    }
    Solution obj;

    cout<<obj.canPartitionKSubsets(vec,k);
}