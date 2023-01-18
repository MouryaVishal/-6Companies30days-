#include<bits/stdc++.h>
using namespace std;

class Solution {
   bool check(vector<int> need){
        for(int i = 0; i < need.size(); i++){
            if(need[i] < 0){
                return false;
            }
        }
        return true;
    }
    map<vector<int>, int> umap;
    
    public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if(umap[needs] > 0){
            return umap[needs];
        }
        int minimum = 0;
        for(int i = 0; i < needs.size(); i++){
            minimum += needs[i] * price[i];
        }        
        for(auto spec : special){
            vector<int> need = needs;
            for(int i = 0; i < need.size(); i++){
                need[i] -= spec[i];
            }
            if(check(need)){
                minimum = min(minimum, spec[spec.size() - 1] + shoppingOffers(price, special, need));    
            }            
        }
        return umap[needs] = minimum;
    }
};


#define fr(i,num) for(int i=0;i<num;i++)
int main(){
    int num;
    cout<<"Enter number of elements:-";
    cin>>num;
    vector<int> price,needs;
    fr(i,num){
        int x;
        cin>>x;
        price.push_back(x);
    }
    fr(i,num){
        int x;
        cin>>x;
        needs.push_back(x);
    }
    int sp;
    cout<<"Number od special offers:-";
    cin>>sp;
    vector<vector<int>> vec(sp,vector<int>(num+1));

    fr(i,sp)
        fr(j,num+1){
            cin>>vec[i][j];
        }
    Solution obj;
    cout<<obj.shoppingOffers(price,vec,needs);
}