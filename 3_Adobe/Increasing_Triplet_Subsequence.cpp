#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // vector<int> temp;
        // temp.push_back(nums[0]);
        // for(int i=1;i<nums.size();i++){
        //     if(nums[i]>temp[temp.size()-1]){
        //         temp.push_back(nums[i]);
        //     }else {
        //         int j=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
        //         temp[j]=nums[i];
        //     }
        //     if(temp.size()==3) return 1;
        // }

        // return 0;

        int first=INT_MAX;
        int sec=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>sec)return true;
            if(nums[i]>first && nums[i]<sec){
                sec=nums[i];
            }else if(nums[i]<first){
                first=nums[i];
            }
        }

        return false;

    }
};

#define fr(i,num) for(int i=0;i<num;i++)
int main(){
    cout<<"Enter number of elements in array:-";
    int num;
    cin>>num;
    vector<int> vec;
    fr(i,num){
        int x;
        cin>>x;
        vec.push_back(x);
    }
    Solution obj;
    cout<<obj.increasingTriplet(vec)<<endl;
}