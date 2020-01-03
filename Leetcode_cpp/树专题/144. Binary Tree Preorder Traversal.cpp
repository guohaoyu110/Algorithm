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
    vector<int>pre;
    vector<int> preorderTraversal(TreeNode* root) {
        //auto p = root;
        //vector<int>pre;
        if (root){
            pre.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return pre;
    }
};
