#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n=text.size();
        set<string> st;

        for(int len=1;len<=n/2;len++){
            int count=0;
            for(int l=0,r=len;r<n;l++,r++){
                if(text[l]==text[r]){
                    count++;
                }else{
                    count=0;
                }

                if(count==len){
                    string str=text.substr(l,r-l+1);
                    st.insert(str);
                    count--;
                }
            }
        }

        return st.size();
    }
};


#define fr(i,num) for(int i=0;i<num;i++)
int main(){
    // ! int num;
    // cout<<"Enter number of element in an array:- ";
    // cin>>num;
    cout<<"Enter string:- ";
    string str;
    cin>>str;
    
    vector<int>  vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
    Solution obj;

    cout<<obj.distinctEchoSubstrings(str);
}