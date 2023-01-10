#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> ans;
        int score=0;
        for(int i=0;i<(1<<12);i++){
            int currArow=numArrows;
            vector<int> temp(12,0);
            for(int j=11;j>=0;j--){
                if(i&(1<<j)){
                    if(currArow<=aliceArrows[j]){
                        continue;
                    }
                    currArow-=(aliceArrows[j]+1);
                    temp[j]=aliceArrows[j]+1;
                }
            }
            for(int j=0;j<12;j++){
                if(i&(1<<j)){
                    temp[j]+=currArow;
                    break;
                }
            }

            int currs=0;
            for(int j=0;j<12;j++){
                if(temp[j]>aliceArrows[j]) currs+=(j);
            }

            if(currs>score){score=currs;ans=temp;}
        }

        return ans;
    }
};;

int main(){
    int num;
    cout<<"Enter number of Arrows:- ";
    cin>>num;
    vector<int> vec(12);
    for(int i=0;i<12;i++){
        cin>>vec[i];
    }
    Solution obj;
    vector<int> ans=obj.maximumBobPoints(num,vec);

    for(auto a:ans){
        cout<<a<<" ";
    }
}