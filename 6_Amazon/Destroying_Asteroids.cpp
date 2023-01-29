#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        sort(begin(a),end(a));

        long long m=mass;
        for(int i=0;i<a.size();i++){
            if(m>=a[i]){
                m+=a[i];
            }else{
                return false;
            }
        }

        return true;
    }
};


int main(){
    cout<<"Enter mass:- ";
    int m;
    cin>>m;
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

    cout<<obj.asteroidsDestroyed(m,vec);
}