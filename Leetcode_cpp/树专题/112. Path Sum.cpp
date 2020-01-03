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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right) return root->val == sum;//这个极端情况，如果root节点就是等于sum
        //这个情况就是递归的终止情况
        if (root->left&&hasPathSum(root->left,sum - root->val)) return true;
        if (root->right && hasPathSum(root->right, sum - root->val)) return true;
        return false;
    }
};