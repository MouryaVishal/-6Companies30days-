#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)
class Solution {
public:
    int mod=1e9;
    int maxSumMinProduct(vector<int>& nums) {
        long ans=0;
        vector<long> prifix(nums.size()+1,0),st;
        for(int i=0;i<nums.size();++i){
            prifix[i+1]=prifix[i]+nums[i];
        }

        for(int i=0;i<=nums.size();++i){
            while(!st.empty() && (i==nums.size() || nums[st.back()]>nums[i])){
                int a=st.back();
                st.pop_back();
                ans=max(ans,nums[a]*(prifix[i]-prifix[st.empty()?0:st.back()+1]));
            }
            st.push_back(i);
        }

        return ans%1000000007;
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
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
    Solution obj;
    cout<<obj.maxSumMinProduct(vec)<<endl;
}