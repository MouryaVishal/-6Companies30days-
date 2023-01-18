#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> val={"0","1"};
    bool func(string curr,int k,unordered_map<string,bool> &mp){
        if(k==0){
            if(mp.find(curr)==mp.end())
                return false;
            return true;
        }
        for(int i=0;i<2;i++){
            string temp=curr+val[i];
            bool flag=func(temp,k-1,mp);
            if(flag==false)return false;
        }

        return true;
            
    }

public:
    bool hasAllCodes(string s,  int k) {
        if(k>s.size()) return false;
        // set<string> st;
        // int total=(1<<k);
        // for(int i=0;i<s.size()-k+1;i++){
        //     string temp=s.substr(i,k);
        //     if(!st.count(temp)){
        //         st.insert(temp);
        //         total--;
        //         if(total==0)return true;
        //     }
        // }

        // return false;


        // if(k>s.size())return false;

        unordered_map<string,bool> mp;

        for(int i=0;i<s.size()-k+1;i++){
            string temp=s.substr(i,k);
            mp[temp]=1;
        }

        return mp.size()==(1<<k);
    }
};


#define fr(i,num) for(int i=0;i<num;i++)
int main(){
    // int num;
    // cout<<"Enter number of element in an array:- ";
    // cin>>num;
    vector<int>  vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;

    string str;
    cin>>str;
    int valk;
    cin>>valk;
    Solution obj;
    cout<<obj.hasAllCodes(str,valk);
}