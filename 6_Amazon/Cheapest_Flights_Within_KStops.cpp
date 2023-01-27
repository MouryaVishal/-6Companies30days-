#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> mp;
        for(auto a:flights){
            mp[a[0]].push_back({a[1],a[2]});
        }

        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> dis(n,INT_MAX);

        while(!q.empty()){
            auto a=q.front();
            q.pop();
            if(a.first>k)continue;
            for(auto ng:mp[a.second.first]){
                if(a.second.second+ng.second<dis[ng.first] && a.first<=k){
                    dis[ng.first]=a.second.second+ng.second;
                    q.push({a.first+1,{ng.first,dis[ng.first]}});
                }
            }
        }

        return dis[dst]==INT_MAX?-1:dis[dst];
    }
};

int main(){
    int num;
    cout<<"Enter number of nodes:-";
    cin>>num;
    
    vector<string> svec;
    vector<vector<int>> dvec;
    cout<<"Enter number od flights:- ";
    int f;
    cin>>f;
    fr(i,f){
        vector<int>  vec;
        fr(j,3){
            int x;
            cin>>x;
            vec.push_back(x);
        }
        dvec.push_back(vec);
    }

    cout<<"Enter number of src:-"; 
    int src;
    cin>>src;
    cout<<"Enter number of dst:- ";
    int dst;
    cin>>dst;

    cout<<"Enter stops:- ";
    int s;
    cin>>s;
    vector<vector<string>> sdvec;
    Solution obj;
    cout<<obj.findCheapestPrice(num,dvec,src,dst,s)<<endl;
}