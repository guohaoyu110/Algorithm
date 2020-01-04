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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        //可能有多种可能性满足这个要求
        vector<vector<int>> path;
        if (!root) return path;
        if (!root->left&&!root->right) return path;
        if (root->left&&pathSum(root->left,sum-root->val)) path.push_back(root->val);
        if (root->right&&pathSum(root->right,sum-root->val)) path.push_back(root->val);
        return path;
    }
};