#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ans=0;
    pair<int,int>  func(TreeNode* root){
        if(root==NULL) return {0,0};

        pair<int,int> left=func(root->left);
        pair<int,int> right=func(root->right);

        if(root->val==(left.first+right.first+root->val)/(1+left.second+right.second)){
            ans++;
        }

        return {left.first+right.first+root->val,1+left.second+right.second};

    }
public:
    int averageOfSubtree(TreeNode* root) {
        func(root);
        return ans;
    }
};

#define fr(i,num) for(int i=0;i<num;i++)
int main(){
    Solution obj;
}