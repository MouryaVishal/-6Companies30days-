#include<bits/stdc++.h>
using namespace std;

class Solution {
    int stepsTill(long  n, long n1, long n2) {
        int steps = 0;
        while (n1 <= n) {
            steps += min(n + 1, n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        return steps;
    }
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k = k - 1;
        while (k > 0) {
            int steps = stepsTill(n, curr, curr + 1);
            if (steps <= k) {
                curr += 1;
                k -= steps;
            } else {
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }
};

#define fr(i,num) for(int i=0;i<num;i++)
int main(){
    cout<<"Enter a number:- ";
    int num;
    cin>>num;
    int k;
    cout<<"Enter value of k:- ";
    cin>>k;
    Solution obj;

    cout<<obj.findKthNumber(num,k);
}