#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)
class Solution {
    struct PairCmp{
        bool operator()(const pair<int,string>& lhs, const pair<int,string>& rhs) const
        { 
            if(lhs.first!=rhs.first) return lhs.first<rhs.first;
            return lhs.second > rhs.second; 
        }
    };

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto &a:words){
            mp[a]++;
        }

        set<pair<int,string>,PairCmp> st;
        for(auto &a:mp){
            st.insert({a.second,a.first});
        }
        vector<string> ans;

        for(auto a=st.rbegin();a!=st.rend() && k;a++ ,k--){
            auto p=*a;
            // if(p.)
            ans.push_back(p.second);
        }

        return ans;
    }
};

int main(){
    int num;
    cout<<"Enter number of words in an array:- ";
    cin>>num;
    vector<int>  vec;
    vector<string> svec;
    fr(i,num){
        string s;
        cin>>s;
        svec.push_back(s);
    }
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
    Solution obj;
    cout<<"Enter k:-";
    int k;
    cin>>k;
    vector<string> ans=obj.topKFrequent(svec,k);
    fr(i,ans.size()){
        cout<<ans[i]<<" ";
    }

}