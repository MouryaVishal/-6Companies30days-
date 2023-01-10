#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& tran) {
        int n=tran.size();
        vector<string> name(n);
        vector<int> time(n);
        vector<int> amount(n);
        vector<string> city(n);
        for(int i=0;i<n;i++){
            string a=tran[i];
            string s="";
            int n=0,t=0,m=0,c=0;
            for(int j=0;j<=a.size();j++){
                if(a[j]==',' || j==a.size()){
                    if(n==0){
                        name[i]=s;
                        n=1;
                    }else if(t==0){
                        time[i]=stoi(s);
                        t=1;
                    }else if(m==0){
                        amount[i]=stoi(s);
                        m=1;
                    }else{
                        city[i]=s;
                    }
                    s="";
                }else{
                    s+=a[j];
                }
            }
        }

        vector<bool> ans(n,0);

        for(int i=0;i<n;i++){
            // cout<<amount[i]<<endl;
            if(amount[i]>1000){
                ans[i]=1;
            }
            for(int j=i+1;j<n;j++){
                if(name[i]==name[j] && city[i]!=city[j] && abs(time[i]-time[j])<=60){
                    ans[i]=1;
                    ans[j]=1;
                }
            }
        }

        vector<string> invalid;
        for(int i=0;i<n;i++){
            if(ans[i]){
                invalid.push_back(tran[i]);
            }
        }

        return invalid;
    }
};

int main(){
    int num;
    cout<<"Enter number number of transactions:- ";
    cin>>num;
    cout<<"format of string :-alice,20,800,mtv \n";
    vector<string> str(num);
    for(int i=0;i<num;i++){
        cin>>str[i];
    }
    Solution obj;
    vector<string> asn=obj.invalidTransactions(str);
    for(auto a:asn)cout<<a<<" ";
}