#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";

        string temp="";
        int flag=0;
        string ans="";
        long long num;
        long long demo;
        if(numerator<0 && denominator<0 ){
        }else if (numerator<0 || denominator<0){
            flag=1;
        }
        if(numerator<0){
            num=-1*(long long)numerator;
        }else{
            num=numerator;
        }
        if(denominator<0){
            demo=-1*(long long)denominator;
        }else{
            demo=denominator;
        }

        long long  q=num/demo;
        long long  r=num%demo;
        temp+=to_string(q);
        // cout<<"r"<<temp<<endl;
        if(r==0){
            if(flag){
                return "-"+temp;
            }
            return temp;
        }else{
            temp+=".";
            unordered_map<long long ,long long> mp;
            mp[r]=temp.size();
            while(r!=0){
                r*=10;
                q=r/demo;
                r=r%demo;
                temp+=to_string(q);
                if(mp[r]){
                    if(flag){
                        ans="-"+temp.substr(0,mp[r])+"("+temp.substr(mp[r],temp.size()-1)+")";
                    }else{
                        ans+=temp.substr(0,mp[r])+"("+temp.substr(mp[r],temp.size()-1)+")";
                    }
                    return ans;
                }else{
                    mp[r]=temp.size();
                }
            }
        }
        if(flag){
            return "-"+temp;
        }
        return temp;
    }
};



#define fr(i,num) for(int i=0;i<num;i++)
int main(){
    cout<<"Enter numerator:- ";
    int num;
    cin>>num;
    cout<<"Enter denominator:- ";
    int demo;
    cin>>demo;
    Solution obj;

    cout<<obj.fractionToDecimal(num,demo);
}