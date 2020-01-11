/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int>inorder;
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return vector<int>{};
        if (root){
            inorderTraversal(root->left);//root->left是NULL自然会走到下面这一步
            //代码再走到NULL的位置会自动进行回溯的
            inorder.push_back(root->val);
            inorderTraversal(root->right);
        }
        return inorder;
    }
    
};
