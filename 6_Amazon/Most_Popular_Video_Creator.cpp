#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)

class Solution {
public:
    struct video{
    long totalView = 0;
    string smallestID;
    int cMaxView = 0;
};

vector<vector<string>> mostPopularCreator(vector<string>& c, vector<string>& ids, vector<int>& views){
    unordered_map<string, video> mp;
    long count = 0;

    for (int i = 0; i < c.size(); i++){
        if (!mp.count(c[i])){
            mp[c[i]] = { views[i], ids[i], views[i] };
            count = max(count, mp[c[i]].totalView);
            continue;
        }
    
        mp[c[i]].totalView += views[i];
        if (mp[c[i]].cMaxView < views[i] || (mp[c[i]].cMaxView == views[i] && ids[i] < mp[c[i]].smallestID)) {
            mp[c[i]].cMaxView = views[i];
            mp[c[i]].smallestID = ids[i];
        }

        count = max(count, mp[c[i]].totalView);
    }

    vector<vector<string>> ans;
    for (auto &r: mp)
        if (r.second.totalView == count)
            ans.push_back({ r.first, r.second.smallestID });

    return ans;
}
};

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
    vector<string> svec;
    fr(i,num){
        string s;
        cin>>s;
        svec.push_back(s);
    }
    vector<string> svec1;
    fr(i,num){
        string s;
        cin>>s;
        svec1.push_back(s);
    }
    vector<vector<int>> dvec;
    Solution obj;
    vector<vector<string>> sdvec=obj.mostPopularCreator(svec,svec1,vec);


}