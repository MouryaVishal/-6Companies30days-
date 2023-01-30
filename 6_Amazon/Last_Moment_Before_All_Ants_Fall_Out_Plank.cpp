#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxi=0;
        for(int i=0;i<left.size();i++){
            maxi=max(maxi,left[i]);
        }
        for(int i=0;i<right.size();i++){
            maxi=max(maxi,n-right[i]);
        }

        return maxi;

    }
};

int main(){
    int num;
    cout<<"Enter length of planks:- ";
    cin>>num;
    vector<int>  vec;
    vector<int>  vec1;

    cout<<"Enter number of left moving ants:-";
    int l;
    cin>>l;
    fr(i,l){
        int x;
        cin>>x;
        vec.push_back(x);
    }
    cout<<"Enter number of right moving ants:-";
    int r;
    cin>>r;
    fr(i,r){
        int x;
        cin>>x;
        vec1.push_back(x);
    }
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
    Solution obj;

}