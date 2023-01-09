#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        vector<pair<int,int>> vec;
        for(int i=0;i<p.size();i++){
            vec.push_back({c[i],p[i]});
        }

        sort(vec.begin(),vec.end());

        int totalCap=w;
        priority_queue<int> q;
        for(int i=0;i<vec.size() && k>0;i++){
            while(i<p.size() && totalCap>=vec[i].first){
                q.push(vec[i].second);
                i++;
            }
            if(q.size()==0){
                return totalCap;
            }
            i--;
            totalCap+=q.top();
            q.pop();
            k--;
        }

        while(k>0 && q.size()!=0){
            totalCap+=q.top();
            q.pop();
            k--;
        }

        return totalCap;
    }
};
int main(){
    int k;
    cout<<"Enter k:- ";
    cin>>k;
    int w;
    cout<<"Enter W:-";
    cin>>w;
    int num;
    cout<<"Enter number of elements in Arrays:- ";
    cin>>num;
    vector<int> Profit(num);
    for(int i=0;i<num;i++){
        cin>>Profit[i];
    }
    vector<int> cap(num);
    for(int i=0;i<num;i++){
        cin>>cap[i];
    }
    Solution obj;
    cout<<obj.findMaximizedCapital(k,w,Profit,cap)<<endl;
}