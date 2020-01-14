/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//这是二叉树的很典型的题目，从中序和后序来构造二叉树
//前序和后序是不好构造二叉树的
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        vector<int>result,left,right;



        
    }
    TreeNode* dfs(vector<int>&in, vector<int>&post, int il, int ir, int pl, int pr){
};