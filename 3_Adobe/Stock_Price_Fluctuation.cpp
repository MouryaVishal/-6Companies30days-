#include<bits/stdc++.h>
using namespace std;

class StockPrice {
    map<int,int> mp;
    multiset<int> val;
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(mp.find(timestamp)!=mp.end()){
            val.erase(val.find(mp[timestamp]));
        }
        mp[timestamp]=price;
        val.insert(price);
    }
    
    int current() {
        return mp.rbegin()->second;
    }
    
    int maximum() {
        return *val.rbegin();
    }
    
    int minimum() {
        return *val.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */

#define fr(i,num) for(int i=0;i<num;i++)
int main(){
    StockPrice obj;
}