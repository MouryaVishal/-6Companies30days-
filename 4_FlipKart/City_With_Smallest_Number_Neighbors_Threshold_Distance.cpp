#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }
        for(auto a:edges){
            dist[a[0]][a[1]]=a[2];
            dist[a[1]][a[0]]=a[2];
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX)continue;
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }

        int city=-1;
        int countMax=n;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=dt){
                    count++;
                }
            }
            if(count<=countMax){
                city=i;
                countMax=count;
            }
        }

        return city;
    }
};



#define fr(i,num) for(int i=0;i<num;i++)
int main(){
    int num;
    cout<<"Enter number of city:- ";
    cin>>num;
    vector<string> svec;
    vector<vector<int>> dvec;
    cout<<"Number of edges:- ";
    int e;
    cin>>e;
    for(int i=0;i<e;i++){
        vector<int>  vec;
        for(int j=0;j<3;j++){
            int x;
            cin>>x;
            vec.push_back(x);
        }
        dvec.push_back(vec);
    }
    cout<<"Enter distanceThreshold:- ";
    int dt;
    cin>>dt;
    vector<vector<string>> sdvec;
    Solution obj;
    cout<<obj.findTheCity(num,dvec,dt);
}