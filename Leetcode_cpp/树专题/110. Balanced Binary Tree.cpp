/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//这种解法，我整体的思路方向都是对的，但是具体的递归的细节，终止的条件还是有点没有完全考虑清楚！
'''
class Solution {
public:
    //这个是平衡二叉树，不是那种比较大小的
    //是左右的高度差控制在1之内
    
    int isJudge(TreeNode* root){
        if(!root) return 0;
        int left = isJudge(root->left)+1; //为什么这里不需要+1
        int right = isJudge(root->right)+1;
        return abs(left-right);
    }
    
    bool isBalanced(TreeNode* root) {
        //if (!root) return false;
        if(isJudge(root)>1) return false;
        else return true;
        //return false;
    }
};
'''
class Solution {
public:
    int depth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int left = depth(root->left);
        int right = depth(root->right);
        if (left == -1 || right == -1 || abs(left - right) > 1) {
            return -1;
        }
        return max(left, right) + 1;
    }

    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        return depth(root) != -1;
    }
};

//yxc的方法，仅供参考！
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int h;
        return dfs(root, h);
    }

    bool dfs(TreeNode*root, int &height)
    {
        if (!root)
        {
            height = 0;
            return true;
        }

        int left, right;
        if (!dfs(root->left, left)) return false;
        if (!dfs(root->right, right)) return false;

        height = max(left, right) + 1;

        return abs(left - right) <= 1;
    }
};

