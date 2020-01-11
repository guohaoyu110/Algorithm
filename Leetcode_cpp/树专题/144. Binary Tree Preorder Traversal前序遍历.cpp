/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//用递归的方法时间复杂度大了一些
//方法一：递归
class Solution {
public:
    vector<int>pre;
    vector<int> preorderTraversal(TreeNode* root) {
        //auto p = root;
        //vector<int>pre;
        if (root)//当前节点非空
        {
            pre.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return pre;
    }
};

//方法二：不用递归，迭代的方法
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> stk;
    stk.push(root);
    while (!stk.empty()) {
        TreeNode* node = stk.top();
        stk.pop();
        if(node) ans.push_back(node->val);
        else continue;
        if (node->right) stk.push(node->right);
        if (node->left) stk.push(node->left);
    }
    return ans;
}

//方法三：用迭代的放啊

