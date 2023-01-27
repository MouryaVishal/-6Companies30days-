#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)
class Solution {
    int func(int i,string&s,unordered_set<string>&st,string temp){

        if(i==s.size()) return 0;
        temp+=s[i];
        int ans=INT_MIN;
        if(st.find(temp)==st.end()){
            st.insert(temp);
            ans=max(ans,1+func(i+1,s,st,""));
            st.erase(temp);
        }

        return max(ans,func(i+1,s,st,temp));
    }
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        return func(0,s,st,"");
    }
};

int main(){
    string s;
    cout<<"Enter string:- ";
    cin>>s;
    vector<int>  vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
    Solution obj;
    cout<<obj.maxUniqueSplit(s);
}