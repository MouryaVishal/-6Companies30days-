#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int magicalString(int n) {
        if(n<=3)return 1;

        string s="122";
        int i=2;
        int j=2;

        while(j<n){
            if(s[i]=='1'){
                if(s[j]=='1'){
                    s+="2";
                }else{
                    s+="1";
                }
                j++;
            }else{
                if(s[j]=='1'){
                    s+="22";
                }else{
                    s+="11";
                }
                j+=2;
            }
            i++;
        }
        cout<<s<<endl;

        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1')ans++;
        }

        return ans;
    }
};

#define fr(i,num) for(int i=0;i<num;i++)
int main(){
    int num;
    cin>>num;

    Solution obj;

    cout<<obj.magicalString(num)<<endl;
}