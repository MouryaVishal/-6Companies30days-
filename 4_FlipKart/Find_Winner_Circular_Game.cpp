#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)

class Solution {
    int func(int n,int k){
        // if(n==1)return 0;
        // return (func(n-1,k)+k)%n;
        int currans=0;
        for(int i=1;i<=n;i++){
            currans=(currans+k)%i;
        }
        return currans;
    }
public:
    int findTheWinner(int n, int k) {
        return func(n,k)+1;
    }
};


int main(){
    int num;
    cout<<"Enter number of friends:- ";
    cin>>num;
    int k;
    cout<<"Enter value of k:- ";
    cin>>k;
    vector<int>  vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;

    Solution obj;
    cout<<obj.findTheWinner(num,k);
}