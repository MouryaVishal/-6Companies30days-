#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> mp;

        for(auto a:times){
            mp[a[0]].push_back({a[1],a[2]});
        }

        set< pair<int,int> > st;
        st.insert({0,k});
        vector<int> dis(n+1,INT_MAX);
        dis[k]=0;

        while(st.size()!=0){
            auto a=*st.begin();
            st.erase(st.begin());
            int curr=a.second;
            int currDis=a.first;

            for(auto ng:mp[curr]){
                int next=ng.first;
                int nextnodedis=ng.second;
                if(currDis+nextnodedis<dis[next]){
                    auto present=st.find({dis[next],next});
                    if(present!=st.end()){
                        st.erase(present);
                    }
                    dis[next]=currDis+nextnodedis;
                    st.insert({dis[next],next});
                }
            }
        }

        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,dis[i]);
        }
        return ans==INT_MAX?-1:ans;

    }
};


int main(){
    int num;
    cout<<"Enter number of edges:- ";
    cin>>num;
    vector<int>  vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    fr(i,num){
        vector<int>  vec;
        fr(j,3){
            int x;
            cin>>x;
            vec.push_back(x);
        }
        dvec.push_back(vec);
    }

    vector<vector<string>> sdvec;
    Solution obj;
    int node;
    cout<<"Enter number of nodes:- ";
    cin>>node;
    int k;
    cout<<"Enter source:- ";
    cin>>k;

    cout<<obj.networkDelayTime(dvec,num,k);



}