
#include <bits/stdc++.h>
using namespace std;

class Solution {
    long long int ans=0;
    void merge(int l,int mid,int r,vector<int>&nums,int diff){
        int left=l,right=mid+1;
        while(left<=mid && right<=r){
            if(nums[left]<=nums[right]+diff){
                ans+=(r-right+1);
                left++;
            }else{
                right++;
            }
        }
        // vector<int> temp;
        // for(int i=l;i<=r;i++){
        //     temp.push_back(nums[i]);
        // }
        sort(nums.begin()+l,nums.begin()+r+1);
        // int j=0;
        // for(int i=l;i<=r;i++){
        //     nums[i]=temp[j];
        //     j++;
        // }
        return ;
    }
    void mergeSort(int l,int r,vector<int>&nums,int diff){
        if(l==r)return ;
        int mid=(l+r)/2;
        mergeSort(l,mid,nums, diff);
        mergeSort(mid+1,r,nums, diff);
        merge(l,mid,r,nums, diff);
        return ;
    }
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        vector<int> num;
        for(int i=0;i<nums1.size();i++){
            num.push_back(nums1[i]-nums2[i]);
        }
        mergeSort(0,nums1.size()-1,num,diff);
        return  ans;
    }
};
int main()
{
    Solution obj;
    int num;
    cout<<"Enter the number of elements:- ";
    cin>>num;
    cout<<"Array1:- \n";
    vector<int>vec(num);
    for(int i=0;i<num;i++){
        cin>>vec[i];
    }
    cout<<"Array2:- \n";
    vector<int>vec1(num);
    for(int i=0;i<num;i++){
        cin>>vec1[i];
    }

    int diff;
    cout<<"Enter diff:- ";
    cin>>diff;

    cout<<obj.numberOfPairs(vec,vec1,diff)<<endl;


}