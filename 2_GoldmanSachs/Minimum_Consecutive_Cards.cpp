#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int> mp;
        int n=cards.size();
        int j=0;
        int ans=INT_MAX;
        while(j<n){
            if(mp.find(cards[j])!=mp.end()){
                int i=mp[cards[j]];
                ans=min(ans,j-i+1);
                mp[cards[j]]=j;
            }
            mp[cards[j]]=j;
            j++;
        }
        return ans==INT_MAX?-1:ans;
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
    cout<<obj.minimumCardPickup(vec)<<endl;
}