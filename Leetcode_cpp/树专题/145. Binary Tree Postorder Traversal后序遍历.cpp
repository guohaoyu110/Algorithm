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
    vector<int>post;
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return vector<int>{};
        if (root){
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            post.push_back(root->val);
        }
        return post;
    }
};
