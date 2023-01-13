#include<bits/stdc++.h>
using namespace std;

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

#define fr(i,num) for(int i=0;i<num;i++)
int main(){
    cout<<"Enter the string:- ";
    string str;
    cin>>str;

    vector<string> store;
    int num;
    cout<<"Enter number of word in store:- ";
    cin>>num;
    fr(i,num){
        string s;
        cin>>s;
        store.push_back(s);
    }
    Solution obj;

    cout<<obj.numMatchingSubseq(str,store);
}