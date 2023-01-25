#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)

class Solution {
    bool valid(int x,int y,int n){
        return x>=0 && y>=0 && x<n && y<n;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({grid[0][0],{0,0}});
        vis[0][0]=1;

        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};

        while(!q.empty()){
            auto top=q.top();
            q.pop();
            int r=top.second.first;
            int c=top.second.second;
            int curr=top.first;

            if(r==n-1 && c==n-1) return curr;
            for(int i=0;i<4;i++){
                int nx=dx[i]+r;
                int ny=dy[i]+c;
                if(valid(nx,ny,n) && !vis[nx][ny]){
                    q.push({max(curr,grid[nx][ny]),{nx,ny}});
                    vis[nx][ny]=1;
                }
            }
        }

        return 0;
    }
};


int main(){
    int num;
    cout<<"Enter number of element in an array:- ";
    cin>>num;
    vector<int>  vec;
    vector<string> svec;
    vector<vector<int>> dvec;

    
    fr(i,num){
        vector<int>  vec;
        fr(j,num){
            int x;
            cin>>x;
            vec.push_back(x);
        }
        dvec.push_back(vec);
    }

    vector<vector<string>> sdvec;
    Solution obj;

    cout<<obj.swimInWater(dvec);
}