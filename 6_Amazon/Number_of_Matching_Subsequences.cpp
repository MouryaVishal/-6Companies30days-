#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<int,vector<int>> store;
        for(int i=0;i<s.size();i++){
            store[s[i]].push_back(i);
        }

        int ans=0;
        for(int i=0;i<words.size();i++){
            string currWord=words[i];
            int lastIndex=-1;
            for(int j=0;j<currWord.size();j++){
                auto ind=upper_bound(store[currWord[j]].begin(),store[currWord[j]].end(),lastIndex);
                if(ind==store[currWord[j]].end()){
                    break;
                }
                lastIndex=*ind;
                if(j==currWord.size()-1)
                    ans++;
            }
        }

        return ans;
    }
};


int main(){
    string s;
    cout<<"Enter str:- ";
    cin>>s;
    vector<int>  vec;
    vector<string> svec;
    cout<<"Enter number of words:-";
    int n;
    cin>>n;
    fr(i,n){
        string x;
        cin>>x;
        svec.push_back(x);
    }
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
    Solution obj;
    cout<<obj.numMatchingSubseq(s,svec);
}