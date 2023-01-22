#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)

class Solution {
    bool isValid(int x,int y,int n,int m,vector<vector<int>>& grid){
        if(x>=0 && y>=0 && x<n && y<m  && grid[x][y]==0)return true;

        return false;
    }
    void dfs(int i,int j,int n,int m,vector<vector<int>>& grid){
        grid[i][j]=1;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};

        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(isValid(nx,ny,n,m,grid)){
                dfs(nx,ny,n,m,grid);
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i*j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]==0){
                        dfs(i,j,n,m,grid);
                    }
                }
            }
        }

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    ans++;
                    dfs(i,j,n,m,grid);
                }  
            }
        }

        return ans;
    }
};



int main(){
    int row,col;
    cout<<"Enter number of row and col in an array:- ";
    cin>>row>>col;
    vector<string> svec;
    vector<vector<int>> dvec;
    fr(i,row){
        vector<int>  vec;
        fr(j,col){
            int x;
            cin>>x;
            vec.push_back(x);
        }
        dvec.push_back(vec);
    }
    vector<vector<string>> sdvec;
    Solution obj;

    cout<<obj.closedIsland(dvec);
}