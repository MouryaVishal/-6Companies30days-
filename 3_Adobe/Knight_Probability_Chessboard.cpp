#include<bits/stdc++.h>
using namespace std;

class Solution {
    int dx[8]={1,2,2,1,-1,-2,-2,-1};
    int dy[8]={-2,-1,1,2,2,1,-1,-2};

    bool valid(int x,int y,int n){
        return x>=0 && y>=0 && y<n && x<n;
    }
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> curr(n,vector<double>(n,0));
        vector<vector<double>> next(n,vector<double>(n,0));

        curr[row][column]=1;
        for(int m=0;m<k;m++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(curr[i][j]!=0){
                        for(int a=0;a<8;a++){
                            int x=i+dx[a];
                            int y=j+dy[a];
                            if(valid(x,y,n))
                                next[x][y]+=curr[i][j]/8.0;
                        }
                    }
                }
            }
            curr=next;
            vector<vector<double>> temp(n,vector<double>(n));
            next=temp;
        }

        double ans;
        for(auto a:curr){
            for(auto b:a){
                ans+=b;
            }
        }

        return ans;
    }
};

#define fr(i,num) for(int i=0;i<num;i++)
int main(){
    int n,k,r, c;
    cin>>n>>k>>r>>c;

    Solution obj;
    cout<<obj.knightProbability(n,k,r,c);

}