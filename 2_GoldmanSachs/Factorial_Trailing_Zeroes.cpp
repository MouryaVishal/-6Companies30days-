#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int count=0;
        while(n>=5){
            count+=n/5;
            n/=5;
        }
        return count;
    }
};

int main(){
    int num;
    cout<<"Enter number:- ";
    cin>>num;
    Solution obj;
    cout<<obj.trailingZeroes(num)<<endl;
}