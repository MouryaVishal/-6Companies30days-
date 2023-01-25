#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)
class Solution {
    int valid(vector<vector<int>>& statements,int currArr){
        int n=statements.size();
        int count=0;

        for(int i=0;i<n;i++){
            int mask=(1<<i);
            if((mask & currArr)==0)continue;
            count++;

            for(int j=0;j<n;j++){
                if(statements[i][j]==2)continue;
                if(((currArr & (1<<j)) !=0  && statements[i][j]==0) ||
                ((currArr & (1<<j) )==0  && statements[i][j]==1))return -1;
            }
        } 

        return count;
    }
public:
    int maximumGood(vector<vector<int>>& statements) {
        int ans=0;
        int n=statements.size();
        for(int i=0;i<(1<<n);i++){
            int count=valid(statements,i);
            ans=max(ans,count);
        }

        return ans;
    }
};

int main(){
    int num;
    cout<<"Enter number of person:- ";
    cin>>num;
    vector<string> svec;
    vector<vector<int>> dvec;

    fr(i,num){
        vector<int>  vec;
        fr(j,num){
            int x;
            cin>>x;
            vec.push_back(x);
        }
        dvec.push_back(vec);
    }
    vector<vector<string>> sdvec;
    Solution obj;

    cout<<obj.maximumGood(dvec)<<endl;
}
