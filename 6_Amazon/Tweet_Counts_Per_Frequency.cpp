#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)

class TweetCounts {
      unordered_map<string, multiset<int>> mp;
public:
    TweetCounts() {}
    
    void recordTweet(string tweetName, int time) {
        mp[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int d = 86400;
        if (freq[0] == 'm') {
            d = 60;
        } else if (freq[0] == 'h') {
            d = 3600;
        }
        vector<int> r((endTime - startTime) / d + 1);
        const auto s = mp.find(tweetName);
        if (s != mp.end()) {
            for (auto t = s->second.lower_bound(startTime); t != s->second.end() && *t <= endTime; ++t) {
               ++r[(*t - startTime) / d];
            }
        }
        return r;
    }
};

/**
 * Your TweetCounts object will be instantiated and cmped as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */

int main(){
    int num;
    cout<<"Enter number of element in an array:- ";
    cin>>num;
    vector<int>  vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
    TweetCounts obj;
}