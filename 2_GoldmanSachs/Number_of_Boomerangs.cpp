#include<bits/stdc++.h>
using namespace std;

class Solution {
    int dist(vector<int>&v1,vector<int>&v2){
        return ((v1[0]-v2[0])*(v1[0]-v2[0]))+((v1[1]-v2[1])*(v1[1]-v2[1]));
    }
public:
    int numberOfBoomerangs(vector<vector<int>>& p) {
        int ans=0;
        int n=p.size();
        for(int i=0;i<n;i++){
            unordered_map<int,int> mp;
            for(int j=0 ;j<n;j++){
                if(i==j)continue;
                mp[dist(p[i],p[j])]++;
            }
            for(auto a:mp){
                ans+=a.second*(a.second-1);
            }
            mp.clear();
        }

        return ans;
    }
};

int main(){
    int num;
    cout<<"Enter number of points:- ";
    cin>>num;
    vector<vector<int>> vec(num,vector<int>(2,0));
    for(int i=0;i<num;i++){
        for(int j=0;j<2;j++){
            cin>>vec[i][j];
        }
    }
    Solution obj;
    cout<<obj.numberOfBoomerangs(vec)<<endl;
}