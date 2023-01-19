#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)

//  * Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
    pair<int,int> func(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        pair<int,int> left=func(root->left);
        pair<int,int> right=func(root->right);

        return {root->val+left.second+right.second,max(left.first,left.second)+max(right.first,right.second)};
    }
public:
    int rob(TreeNode* root) {
        pair<int,int> p=func(root);

        return max(p.first,p.second);
    }
};

int main(){
    int num;
    cout<<"Enter number of element in an array:- ";
    cin>>num;
    vector<int>  vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
    Solution obj;
}