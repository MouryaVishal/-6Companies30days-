#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum=0;
                for(int r=i-k<0?0:i-k; r>=0 && r<n &&  r<=i+k;r++){
                    for(int c=j-k<0?0:j-k;c>=0 && c<m && c<=j+k ;c++){
                        // cout<<"A"<<endl;
                        sum+=mat[r][c];
                    }
                }
                ans[i][j]=sum;
            }
        }

        return ans;
    }
};

int main(){
    int r,c;
    cout<<"Enter number of row and cols:- ";
    cin>>r>>c;
    vector<string> svec;
    vector<vector<int>> dvec;
    fr(i,r){
        vector<int>  vec;
        fr(j,c){
            int x;
            cin>>x;
            vec.push_back(x);
        }
        dvec.push_back(vec);
    }
    int val;
    cout<<"Enter k:-";
    cin>>val;
    vector<vector<string>> sdvec;
    Solution obj;
    vector<vector<int>> ans =obj.matrixBlockSum(dvec,val);

    fr(i,r){
        fr(j,c)cout<<ans[i][j]<<" ";
        cout<<endl;}
}