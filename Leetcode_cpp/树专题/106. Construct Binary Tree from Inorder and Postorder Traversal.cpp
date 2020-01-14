/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//这是二叉树的很典型的题目，从中序和后序来构造二叉树
//前序和后序是不好构造二叉树的
//这道题目思路算是想清楚了！！！
class Solution {
public:
    unordered_map<int,int> pos;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //vector<int>result,left,right;
        int n = inorder.size();
        for(int i =0;i<n;i++){
            pos[inorder[i]] = i;
        }
        return dfs(postorder,inorder,0,n-1,0,n-1);
    }
    TreeNode* dfs(vector<int>&post, vector<int>&in, int pl, int pr, int il, int ir){
        if (pl > pr) return NULL;
        int k = pos[post[pr]] - il;//找到这个在中序数组中的位置
        TreeNode* root = new TreeNode(post[pr]);
        //root->left = dfs(in,post,il+1,il+k,pl,pl+k-1);
        //root->right = dfs(in,post,)
        root->left = dfs(post,in,pl,pl+k-1,il,il+k-1);
        root->right = dfs(post,in,pl+k,pr-1,il+k+1,ir);
        return root; 
    }
};