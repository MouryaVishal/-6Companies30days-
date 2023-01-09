#include<bits/stdc++.h>
using namespace std;

class Solution {
    int dist(vector<int>& p1,vector<int>& p2){
        return ((p1[1]-p2[1])*(p1[1]-p2[1])+(p1[0]-p2[0])*(p1[0]-p2[0]));
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<int> mp;
        mp.insert(dist(p1,p2));
        mp.insert(dist(p1,p3));
        mp.insert(dist(p1,p4));
        mp.insert(dist(p2,p4));
        mp.insert(dist(p2,p3));
        mp.insert(dist(p3,p4));
        // for(auto a:mp){
        //     cout<<a<<" ";
        // }

        return !mp.count(0) && mp.size()==2;
    }
};

int main(){
    int num;
    cout<<"Enter four points:- ";
    int a,b;
    cin>>a>>b;
    int c,d;
    cin>>c>>d;
    int e,f;
    cin>>e>>f;
    int g,h;
    cin>>g>>h;
    Solution obj;
    vector<int> p1={a,b};
    vector<int> p2={c,d};
    vector<int> p3={e,f};
    vector<int> p4={g,h};
    cout<<obj.validSquare(p1,p2,p3,p4)<<endl;
}