class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // TreeNode* left = root->left;
        // TreeNode* right = root->right;
        dfs(root);
        return root;
    }
    void dfs(TreeNode* node){
        if (node == NULL) return;
        TreeNode* left = node->left, *right = node->right;
        node->left = right; node->right=left;
        if (left !=NULL) dfs(left);
        if (right!=NULL) dfs(right);
    }
};