#include<bits/stdc++.h>
using namespace std;

class Solution {
    long long  mod=(long long )1e9+7;
    int revNumber(int num){
        string str=to_string(num);
        int n=str.size();
        for(int i=0;i<str.size()/2;i++){
            char temp=str[i];
            str[i]=str[n-i-1];
            str[n-i-1]=temp;
        }

        return stoi(str);
    }
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,long long> mp;
        for(auto a:nums){
            mp[a-revNumber(a)]++;
        }
        // cout<<mp.size()<<endl;
        long long ans=0;
        for(auto a:mp){
            long long val=a.second;
            ans=((ans+(val*(val-1))/2)%mod+mod)%mod;
        }

        return ans;
    }
};

int main(){
    int num;
    cout<<"Enter number of elements in Arrays:- ";
    cin>>num;
    cout<<"Enter elements of array:- ";
    vector<int> vec(num);
    for(int i=0;i<num;i++){
        cin>>vec[i];
    }
    Solution obj;
    cout<<obj.countNicePairs(vec)<<endl;
}