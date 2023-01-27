#include<bits/stdc++.h>
using namespace std;


#define fr(i,num) for(int i=0;i<num;i++)
class Solution {
    vector<int> vec;
    vector<int>org;
public:
    Solution(vector<int>& nums) {
        vec=org=nums;
    }
    
    vector<int> reset() {
        return org;
    }
    
    vector<int> shuffle() {
        int n=vec.size();
        int n1=rand()%n;
        int n2=rand()%n;
        swap(vec[n1],vec[n2]);
        return vec;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
int main(){
    int num;
    cout<<"Enter number of element in an array:- ";
    cin>>num;
    vector<int>  vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
    Solution obj(vec);
}