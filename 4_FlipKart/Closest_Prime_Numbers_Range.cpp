#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool arr[1000007]={0};
    // arr[2]=1;
    vector<int> ans;
    void sieve(int n){
        for(long long i=2;i<=n;i++){
            if(arr[i]==0){
                ans.push_back(i);
                for(long long j=i*i;j<=n;j+=i){
                    arr[j]=1;
                }
            }
        }
    }
public:
    vector<int> closestPrimes(int left, int right) {
        sieve(right);
        int n1=-1;
        int n2=-1;
        int i=lower_bound(begin(ans),end(ans),left)-begin(ans);

        for(;i+1<ans.size() ;i++){
            if(n1==-1 || ans[i+1]-ans[i]<n2-n1){
                n1=ans[i];
                n2=ans[i+1];
                if(n2-n1< 3){
                    break;
                }
            }
        }

        return {n1,n2};

    }
};

#define fr(i,num) for(int i=0;i<num;i++)
int main(){
    int l;
    cout<<"Enter left and right limit:- ";
    int r;
    cin>>l>>r;
    Solution obj;
    vector<int> ans=obj.closestPrimes(l,r);

    for(auto a:ans)cout<<a<<"  ";
}