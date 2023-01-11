#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int r=-1;
        int maxi=nums[0];
        for(int i=1;i<nums.size();i++){
            if(maxi>nums[i]){
                r=i;
            }else{
                maxi=max(maxi,nums[i]);
            }
        }
        int n=nums.size();
        int l=n;
        int mini=nums[n-1];

        for(int i=n-2;i>=0;i--){
            if(nums[i]>mini){
                l=i;
            }else{
                mini=min(mini,nums[i]);
            }
        }

        return r-l+1>=0?r-l+1:0;
    }
};

int main(){

    int num;
    cout<<"Enter number of elements in an array:- ";
    cin>>num;

    vector<int> vec;
    for(int i=0;i<num;i++){
        int x;
        cin>>x;
        vec.push_back(x);
    }
    Solution obj;

    cout<<obj.findUnsortedSubarray(vec);
}