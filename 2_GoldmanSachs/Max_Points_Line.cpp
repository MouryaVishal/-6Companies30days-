#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n==1) return 1;

        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<double,int> mp;
            for(int j=0;j<n;j++){
                if(i!=j)
                mp[atan2(points[j][1]-points[i][1],points[j][0]-points[i][0])]++;
            }

            for(auto a:mp){
                ans=max(ans,a.second+1);
            }
        }

        return ans;

    }
};

int main(){
    int num;
    cout<<"Enter number of points:- ";
    cin>>num;
    Solution obj;
    vector<vector<int>> points(num,vector<int>(2));
    for(int i=0;i<num;i++){
        for(int j=0;j<2;j++){
            cin>>points[i][j];
        }
    }
    cout<<obj.maxPoints(points)<<endl;
}