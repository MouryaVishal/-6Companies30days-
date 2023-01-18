#include<bits/stdc++.h>
using namespace std;

#define PII pair<int,string> 
class Compare {
public:
    bool operator()(PII below, PII above)
    {
        if (below.first == above.first) {
            return below.second > above.second ;
        }
        return below.first< above.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto a:words){
            mp[a]++;
        }
        priority_queue<PII ,vector<PII> ,Compare> q;

        for(auto a:mp){
            q.push({a.second,a.first});
        }
        vector<string> ans;
        while(k--){
            ans.push_back(q.top().second);
            q.pop();
        }

        return ans;
    }
};


#define fr(i,num) for(int i=0;i<num;i++)

int main(){
    int num;
    cout<<"Enter number of elementd in an array:-";
    cin>>num;

    vector<string> vec;
    fr(i,num){
        string x;
        cin>>x;
        vec.push_back(x);
    }

    int k;
    cout<<"Enter value of k:-";
    cin>>k;
    Solution obj;

    vector<string> ans=obj.topKFrequent(vec,k);

    fr(i,k){
        cout<<ans[i]<<endl;
    }
}