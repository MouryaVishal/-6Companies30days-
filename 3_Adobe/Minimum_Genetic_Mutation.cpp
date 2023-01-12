#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++) ;


class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(),bank.end());
        if(!st.count(endGene)) return -1;
        queue<string> q;
        q.push(startGene);
        int ans=0;
        string curr;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                curr=q.front();
                q.pop();
                if(curr==endGene) return ans;
                st.erase(curr);
                for(int i=0;i<8;i++){
                    string temp=curr;
                    temp[i]='A';
                    if(st.count(temp)) q.push(temp);
                    temp[i]='C';
                    if(st.count(temp)) q.push(temp);
                    temp[i]='G';
                    if(st.count(temp)) q.push(temp);
                    temp[i]='T';
                    if(st.count(temp)) q.push(temp);
                }
            }
            ans++;
        }

        return -1;
    }
};

int main(){
    cout<<"Enter the starting string:- ";
    string start;
    cin>>start;
    string end;
    cout<<"Enter the end String:- ";
    cin>>end;

    vector<string> vec;
    cout<<"Enter the number of string in bank:- ";
    int num;
    cin>>num;
    fr(i,num){
        string s;
        cin>>s;
        vec.push_back(s);
    }
    Solution obj;

    cout<<obj.minMutation(start,end,vec);
}