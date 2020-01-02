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
//时间复杂度分析：从上到下每个节点仅被遍历一遍，所以时间复杂度是 O(n)O(n)。
'''
(递归) O(n)O(n)
递归判断两个子树是否互为镜像。

两个子树互为镜像当且仅当：

两个子树的根节点值相等；
第一棵子树的左子树和第二棵子树的右子树互为镜像，且第一棵子树的右子树和第二棵子树的左子树互为镜像；
时间复杂度分析：从上到下每个节点仅被遍历一遍，所以时间复杂度是 O(n)O(n)。
'''
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return dfs(root->left,root->right);
    }
    bool dfs (TreeNode* p, TreeNode* q){
        if (!p||!q) return !p && !q;
        //if (p->val == q->val)
        return p->val == q->val&&dfs(p->left,q->right)&&dfs(p->right,q->left);
    }
};