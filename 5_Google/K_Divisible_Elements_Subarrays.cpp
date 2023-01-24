#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int ans=0;
        set<string> st;
        int n=nums.size();

        for(int i=0;i<n;i++){
            // vector<int> temp;
            string str="";
            int count=0;
            for(int j=i;j<n;j++){
                // temp.push_back(nums[j]);
                str+=to_string(nums[j])+"*";
                if(nums[j]%p==0){
                    count++;
                }
                if(count<=k){
                    // cout<<str<<endl;
                    st.insert(str);
                }else{
                    break;
                }
            }
        }

        return st.size();
    }
};


#define fr(i,num) for(int i=0;i<num;i++)
int main(){
    int num;
    cout<<"Enter number of element in an array:- ";
    cin>>num;
    vector<int>  vec;
    fr(i,num){
        int x;
        cin>>x;
        vec.push_back(x);
    }

    cout<<"Enter val of k and p:- ";
    int k,p;
    cin>>k>>p;

    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
    Solution obj;

    cout<<obj.countDistinct(vec,k,p);
}