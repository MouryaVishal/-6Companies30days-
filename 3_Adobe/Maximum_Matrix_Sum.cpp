#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int countneg=0;
        long long ans=0;
        int mini=INT_MAX;
        for(auto a:matrix){
            for(int b:a){
                ans+=abs(b);
                if(b<0){
                    countneg++;
                }

                mini=min(mini,abs(b));
            }
        }

        if(countneg%2==0)return ans;

        return ans-2*mini;
    }
};

#define fr(i,num) for(int i=0;i<num;i++)
int main(){
    int num;
    cout<<"Enter num:- ";
    cin>>num;
    vector<vector<int>> vec(num,vector<int>(num));
    fr(i,num){
        fr(j,num){
            cin>>vec[i][j];
        }
    }
    Solution obj;

    cout<<obj.maxMatrixSum(vec);
}