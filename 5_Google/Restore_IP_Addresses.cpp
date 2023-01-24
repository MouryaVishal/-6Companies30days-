#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int under=256;

        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++){
                for(int x=1;x<=3;x++){
                    for(int y=1;y<=3;y++){
                        if(x+y+i+j==s.size()){
                            string s1=to_string(stoi(s.substr(0,i)));
                            string s2=to_string(stoi(s.substr(i,j)));
                            string s3=to_string(stoi(s.substr(i+j,x)));
                            string s4=to_string(stoi(s.substr(i+j+x,y)));
                            if(stoi(s1)<256 && stoi(s2)<256 && stoi(s3)<256 &&stoi(s4)<256  ){
                                string temp=s1+"."+s2+"."+s3+"."+s4;
                                if(temp.size()==s.size()+3)
                                    ans.push_back(temp);
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};


int main(){
    string str;
    cout<<"Enter string:- ";
    cin>>str;
    vector<string>  vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
    Solution obj;

    vec=obj.restoreIpAddresses(str);
    for(auto a:vec){
        cout<<a<<" ";
    }
}