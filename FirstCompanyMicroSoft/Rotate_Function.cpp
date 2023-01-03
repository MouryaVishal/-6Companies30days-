
// You are given an integer array nums of length n.

// Assume arrk to be an array obtained by rotating nums by k positions clock-wise. We define the rotation function F on nums as follow:

// F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].
// Return the maximum value of F(0), F(1), ..., F(n-1).

// The test cases are generated so that the answer fits in a 32-bit integer.

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=0,initialSum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            initialSum+=(i*nums[i]);
        }
        int maxi=INT_MIN;

        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            initialSum+=sum-(nums[i]*n);
            maxi=max(maxi,initialSum);
        }
        return maxi;
    }
};

int main(){
    cout<<"Constraints:\nn == nums.length\n1 <= n <= 105\n-100 <= nums[i] <= 100"<<endl;
    Solution obj;
    int num;
    cout<<"Enter num:- ";
    cin>>num;
    vector<int> vec(num);
    cout<<"Enter vector:- ";
    for(int i=0;i<num;i++)cin>>vec[i];

    cout<<obj.maxRotateFunction(vec)<<endl;
}