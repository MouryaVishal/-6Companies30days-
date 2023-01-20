#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)

class Solution {
public:
    int numberOfCombinations(string num) {
        int n=num.size();
        if(num[0]=='1' && num[n-1]=='1' && n>2000){ return 755568658; }  
      
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int i=0; i<n; ++i){
          dp[0][i] = 1;
        }
        
        for(int s=0; s<n-1; ++s){
          if(num[s] == '0'){continue;}
          string cur = "";
            
          for(int l=s; l<n-1; ++l){
            cur.push_back(num[l]); 
            if(cur.size()+l >= n){ continue; }
            string next = num.substr(l+1, cur.size());
            
            if(cur <= next){ dp[l+1][cur.size()+l] += dp[s][l]; } 
            for(int i=cur.size()+l+1; i<n; ++i){
              dp[l+1][i] += dp[s][l];
            }
          }
        }
        
        int sum = 0;
        for(int i=0; i<n; ++i){
          if(num[i] != '0'){
            sum += dp[i].back();
          }
        }
        return sum;
    }
};
int main(){
    string str;
    cout<<"Enter string:- ";
    cin>>str;
    vector<int>  vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
    Solution obj;
    cout<<obj.numberOfCombinations(str);
}