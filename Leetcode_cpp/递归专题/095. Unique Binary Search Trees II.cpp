/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//这种题目用递归和动态规划的思路都是可以写的！
class Solution {
public:
    vector<TreeNode*> dfs(int l, int r){
        vector<TreeNode*> res;
        if (l > r)//这个是递归的终止条件
        {
            res.push_back(NULL);
            return res;
        }

        for(int i = l;i<=r;i++){//先以1为root，一直到最后n为root
        //如果root = k，左子树一定是1到k-1 右子树一定是k+1到n
            vector<TreeNode*>left = dfs(l,i-1), right = dfs(i+1,r);//构建左子树和右子树
            for(auto lc:left){
                for(auto rc:right){
                    TreeNode *root = new TreeNode(i);//这里要对每种不同组合建立一个新的根节点，否则这些根节点的地址是一样的，那么它们的左右儿子在内层循环时会被不断覆盖掉。
                    root->left = lc;
                    root->right = rc;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    //这个递归函数的边界是什么呢？
    // 如果min>max，那么就到了我们的终止条件
    vector<TreeNode*> generateTrees(int n) {
        if(!n) return vector<TreeNode*>();
        return dfs(1,n);
    }
};