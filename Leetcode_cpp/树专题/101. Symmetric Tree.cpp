/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//树的题目的根本思想是递归

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return !root || dfs(root->left,root->right);
    }
    bool dfs (TreeNode* p, TreeNode* q){
        if (!p||!q) return !p && !q;
        //if (p->val == q->val)
        return p->val == q->val&&dfs(p->left,q->right)&&dfs(p->right,q->left);
    }
};