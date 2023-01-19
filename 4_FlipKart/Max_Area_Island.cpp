#include<bits/stdc++.h>
using namespace std;

class Solution {
    int areaFun(int i,int j,vector<vector<int>>& visited,vector<vector<int>>& grid){
        if(i<0 || j<0 || j>=grid[0].size() ||i>=grid.size() || visited[i][j] || grid[i][j]==0)
            return 0;
        visited[i][j]=1;
        return (1+areaFun(i+1,j,visited,grid)+areaFun(i-1,j,visited,grid)
                +areaFun(i,j-1,visited,grid)+areaFun(i,j+1,visited,grid));  
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ans=max(ans,areaFun(i,j,visited,grid));
            }
        }
        
        return ans;
    }
};


#define fr(i,num) for(int i=0;i<num;i++)
int main(){
    int r,c;
    cout<<"Enter number of row and col in an array:- ";
    cin>>r>>c;
    vector<int>  vec;
    vector<string> svec;
    vector<vector<int>> dvec;

    fr(i,r){
        fr(j,c){
            int x;
            cin>>x;
            vec.push_back(x);
        }
        dvec.push_back(vec);
    }

    vector<vector<string>> sdvec;
    Solution obj;
    cout<<obj.maxAreaOfIsland(dvec)<<endl;
}