#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto a:nums){
            mp[a]++;
        }
        unordered_map<int,int> nextElement;;

        for(auto a:nums){
            if(mp[a]<=0){
                continue;
            }else if(nextElement[a]>0){
                nextElement[a]--;
                mp[a]--;
                nextElement[a+1]++;
            }else if(mp[a]>0 && mp[a+1]>0 && mp[a+2]>0){
                mp[a]--;
                mp[a+1]--;
                mp[a+2]--;
                nextElement[a+3]++;
            }else{
                return 0;
            }
        }

        return 1;
    }
};

int main(){
    int num;
    cout<<"Enter number of elements in Arrays:- ";
    cin>>num;
    vector<int> vec(num);
    for(int i=0;i<num;i++){
        cin>>vec[i];
    }
    Solution obj;
    cout<<obj.isPossible(vec)<<endl;
}