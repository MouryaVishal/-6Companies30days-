#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int,vector<int>> adj;
    void dfsParent(int node,int par,vector<int>&dis,vector<int>&parent,int dist){
        parent[node]=par;
        dis[node]=dist;
        for(auto a:adj[node]){
            if(a!=par){
                dfsParent(a,node,dis,parent,dist+1);
            }
        }
    }
    int dfsAns(int node,int par,vector<int>&amt){
        int curr=amt[node];
        int maxi=INT_MIN;
        for(auto a:adj[node]){
            if(a!=par){
                maxi=max(maxi,dfsAns(a,node,amt));
            }
        }
        if(maxi==INT_MIN)return curr;

        return maxi+curr;
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        for(auto a:edges){
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }
        int n=amount.size();
        vector<int> dis(n);
        vector<int> parent(n);
        dfsParent(0,-1,dis,parent,0);

        int currbob=bob;
        int distBob=0;
        while(currbob!=0){
            if(dis[currbob]>distBob){
                amount[currbob]=0;
            }else if(dis[currbob]==distBob){
                amount[currbob]/=2;
            }
            currbob=parent[currbob];
            distBob++;
        }
        return dfsAns(0,-1,amount);
    }
};

int main()
{
    Solution obj;
    int num;
    cout<<"Enter the number of Node:- ";
    cin>>num;
    int numEdges;
    cout<<"Number of Edges:- "
    cin>>numEdges;
    cout<<"Enter edges;- \n";
    vector<vector<int>> edged(numEdges,vector<int>(2));
    for(int i=0;i<numEdges;i++){
        for(int j=0;j<2;j++){
            cin>>edged[i][j];
        }
    }

    cout<<"Enter amount of each node:- ";
    vector<int> amount(num);
    for(int i=0;i<num;i++){
        cin>>amount[i];
    }

    cout<<"Enter Bob node:- ";
    int bob;
    cin>>bob;

    cout<<obj.mostProfitablePath(edged,bob,amount);

}