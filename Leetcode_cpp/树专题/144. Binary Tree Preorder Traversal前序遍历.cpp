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
        if (!root) return vector<int>{};
        if (root)//当前节点非空
        {
            pre.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return pre;
    }
};

//方法二：不用递归，迭代的方法，这种方法很好啦！
class Solution{
public:
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
            if (node->left) stk.push(node->left);//这样可以让左边的节点先pop，然后进入ans数组
        }
        return ans;
    }
};
//方法三：
'''
算法
(Morris-traversal) O(n)
用Morris-traversal算法遍历二叉树。Morris-traversal算法详见Recover Binary Search Tree。

算法步骤：
从根节点开始遍历，直至当前节点为空为止：

如果当前节点没有左儿子，则打印当前节点的值，然后进入右子树；
如果当前节点有左儿子，则找当前节点的前驱。
(1) 如果前驱节点的右儿子为空，说明左子树没遍历过，则先将前驱节点的右儿子置成当前节点，方便回溯，然后打印根节点，并进入左子树遍历；
(2) 如果前驱节点的右儿子为当前节点，说明左子树已被遍历过，则将前驱节点的右儿子恢复为空，然后进入右子树继续遍历；
时间复杂度分析：Morris-traversal算法的时间复杂度是 O(n)，空间复杂度是 O(1)。

'''
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        while (root)
        {
            if (!root->left)
            {
                res.push_back(root->val);
                root = root->right;
            }
            else
            {
                TreeNode *pre = root->left;
                while (pre->right && pre->right != root) 
                    pre = pre->right;
                if (pre->right) pre->right = 0, root = root->right;
                else
                {
                    pre->right = root;
                    res.push_back(root->val);
                    root = root->left;
                }
            }
        }
        return res;
    }
};
