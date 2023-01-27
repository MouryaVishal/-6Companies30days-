#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)

class Solution {
public:
    int maxCoins(vector<int>& p) {
        sort(begin(p),end(p));
        int n=p.size();
        int ans=0;
        int count=n/3;
        for(int i=n-2;i>=0 && count;i-=2,count--){
            cout<<p[i]<<endl;
            ans+=p[i];
        }
        

        return ans;
    }
};


int main(){
    int num;
    cout<<"Enter number of element in an array:- ";
    cin>>num;
    vector<int>  vec;
    fr(i,num){
        int x;
        cin>>x;
        vec.push_back(x);
    }
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
    Solution obj;

    cout<<obj.maxCoins(vec);
}