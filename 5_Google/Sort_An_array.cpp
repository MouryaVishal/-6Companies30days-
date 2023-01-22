#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)

class Solution {
    void merge(int l,int mid,int e,vector<int>&nums){
        int left=mid-l+1;
        int right=e-mid;
        vector<int> lt(left);
        vector<int> rt(right);
        for(int i=0;i<left;i++){
            lt[i]=nums[l+i];
        }
        for(int i=0;i<right;i++){
            rt[i]=nums[mid+1+i];
        }

        int i=0,j=0;
        int k=l;

        while(i<left && j<right){
            if(lt[i]<rt[j]){
                nums[k]=lt[i];
                i++;
            }else{
                nums[k]=rt[j];
                j++;
            }
            k++;
        }

        while(i<left){
            nums[k]=lt[i];
            i++,k++;
        }

        while(j<right){
            nums[k]=rt[j];
            j++,k++;
        }
    }
    void mergerSort(int l,int r,vector<int>&nums){
        if(l<r){
            int mid=(l+r)/2;
            mergerSort(l,mid,nums);
            mergerSort(mid+1,r,nums);
            merge(l,mid,r,nums);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergerSort(0,n-1,nums);
        return nums;
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
    vector<int> ans=obj.sortArray(vec);
    fr(i,num)cout<<ans[i]<<" ";
}