#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)

class Solution {
public:
        string predictPartyVictory(string senate) {
        queue<int> q1, q2;
        int n = senate.length();
        for(int i = 0; i<n; i++)
            (senate[i] == 'R')?q1.push(i):q2.push(i);

        while(!q1.empty() && !q2.empty()){
            int r = q1.front(), d = q2.front();
            q1.pop(), q2.pop();
            (r < d)?q1.push(r+ n):q2.push(d + n);
        }
        return (q1.size() > q2.size())? "Radiant" : "Dire";
    }
};

int main(){
    string str;
    cout<<"Enter senate:- ";
    cin>>str;
    vector<int>  vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
    Solution obj;
    cout<<obj.predictPartyVictory(str)<<endl;
}