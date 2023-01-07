#include<bits/stdc++.h>
using namespace std;


//  Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
    vector<int> vec1;
    vector<int> vec2;
    void inorder(TreeNode* root,vector<int>&vec){
        if(root==NULL) return ;
        inorder(root->left,vec);
        vec.push_back(root->val);
        inorder(root->right,vec);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        inorder(root1,vec1);
        inorder(root2,vec2);
        vector<int> ans;

        int n1=vec1.size();
        int n2=vec2.size();

        int i=0;
        int j=0;
        while(i<n1 && j<n2){
            if(vec1[i]<=vec2[j]){
                ans.push_back(vec1[i]);
                i++;
            }else{
                ans.push_back(vec2[j]);
                j++;
            }
        }
        while(i<n1){
            ans.push_back(vec1[i]);
            i++;
        }
        while(j<n2){
            ans.push_back(vec2[j]);
            j++;
        }

        return ans;
    }
};

int main(){
    int num;
    cout<<"Enter number:- ";
}