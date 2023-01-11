#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector <int> vec;
        priority_queue <int> q;
        int r = grid.size();
        int c = grid[0].size();
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                q.push(grid[i][j]);
            }
        }
        
        int h = 1;
        int height = (2 * h) + 1;
        
        while (height <= r && height <= c) {
            
            for (int i = 0; i < r && (r - i) >= height; i++) {
                for (int j = h; j < c - h; j++) {
                    
                    int s = 0;
                    
                    int top = grid[i][j];
                    s += top;
                    
                    for (int li = 1; li <= h; li++) {
                        s += grid[i + li][j - li];
                    }
                    
                    for (int ri = 1; ri <= h; ri++) {
                        s += grid[i + ri][j + ri];
                    }
                    
                    int bottom = grid[i + height - 1][j];
                    int bi = i + height - 1;
                    
                    for (int bl = 1; bl <= (h - 1); bl++) {
                        s += grid[bi - bl][j - bl];
                    }
                    
                    for (int br = 1; br <= (h - 1); br++) {
                       s += grid[bi - br][j + br]; 
                    }
                    
                    s += bottom;
                    
                    q.push(s);
                }
            }
            
            h += 1;
            height = (2 * h) + 1;
        }
        
        unordered_set <int> top;
        int k = 3;
        
        while (k > 0 && !q.empty()) {
            int el = q.top(); q.pop();
            if (top.find(el) == top.end()) {
                top.insert(el);
                k--;
            }
        }
        
        for (auto i: top) {
            vec.push_back(i);
        }
        
        sort(vec.begin(), vec.end(), greater <int>());
        
        return vec;
    }
};

int main(){
    int num;
    cin>>num;
    vector<vector<int>> vec(num,vector<int>(num));
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            cin>>vec[i][j];
        }
    }
    Solution obj;

    vector<int> ans=obj.getBiggestThree(vec);

    for(auto a: ans) cout<<a<< " ";
}