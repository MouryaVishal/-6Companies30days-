#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int> mp;
        for(auto a:barcodes){
            mp[a]++;
        }
        priority_queue<pair<int,int>> q;
        for(auto a:mp){
            q.push({a.second,a.first});
        }

        vector<int> ans;
        while(!q.empty()){
            pair<int,int> f=q.top();
            q.pop();
            ans.push_back(f.second);
            pair<int,int> s;
            int temp=0;
            if(q.size()!=0){
                temp=1;
                s=q.top();
                q.pop();
                ans.push_back(s.second);
            }
            if(f.first-1!=0){
                q.push({f.first-1,f.second});
            }
            if(temp && s.first-1!=0){
                q.push({s.first-1,s.second});
            }
        }
        return ans;
    }
};


#define fr(i,num) for(int i=0;i<num;i++)
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

    vector<int> ans=obj.rearrangeBarcodes(vec);
    fr(i,num)cout<<ans[i]<<" ";
}