#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)

class Solution {
public:
    string customSortString(string order, string s) {

        sort(begin(s),end(s),[&](char a,char b){return order.find(a)<order.find(b);});
        return s;

        // vector<int> vec(26,0);
        // for(auto a:s){
        //     vec[a-'a']++;
        // }

        // string ans="";
        // for(auto a:order){
        //     int l=vec[a-'a'];
        //     while(l--)ans+=a;
        //     vec[a-'a']=0;
        // }

        // for(int i=0;i<26;i++){
        //     if(vec[i]!=0){
        //         int l=vec[i];
        //         while(l--)ans+=(char)(i+97);
        //     }
        // }

        // return ans;

        
        // unordered_map<char,int> mp;
        // for(auto a:s){
        //     mp[a]++;
        // }
        // string ans="";

        // for(auto a:order){
        //     if(mp[a]){
        //         int l=mp[a];
        //         while(l--){
        //             ans+=a;
        //         }
        //         mp.erase(a);
        //     }
        // }

        // for(auto a:mp){
        //     cout<<a.first<<" ";
        //     int l=a.second;
        //     while(l--){
        //         ans+=a.first;
        //     }
        // }
        // return ans;
    }
};

int main(){
    // int num;
    // cout<<"Enter number of element in an array:- ";
    // cin>>num;
    vector<int>  vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
    string order,s;
    cin>>order>>s;
    Solution obj;
    cout<<obj.customSortString(order,s)<<endl;
}