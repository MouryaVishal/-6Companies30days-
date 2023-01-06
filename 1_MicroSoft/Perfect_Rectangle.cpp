
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int> , int> mp;
        for(auto a:rectangles){
            mp[{a[0],a[1]}]++;
            mp[{a[2],a[3]}]++;
            mp[{a[0],a[3]}]--;
            mp[{a[2],a[1]}]--;
        }
        int count=0;
        for(auto a:mp){
            // cout<<a.first.first<<" "<<a.first.second<<" "<<a.second<<endl;
            if(abs(a.second)==1){
                count++;
            }else if(abs(a.second)!=1&&abs(a.second)!=0 ){
                return false;
            }
        }
        return count==4;
    }
};

int main()
{
    Solution obj;
    int num;
    cout<<"Enter the number of rectangles:- ";
    cin>>num;
    vector<vector<int>> vec(num,vector<int>(4));
    for(int i=0;i<num;i++){
        for(int j=0;j<4;j++){
            cin>>vec[i][j];
        }
    }
    cout<<obj.isRectangleCover(vec)<<endl;

}