/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//方法一：递归
class Solution {
public:
    vector<int>inorder; //不能放在里面，不然会被反复初始化
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return vector<int>{};
        if (root){
            inorderTraversal(root->left);//root->left是NULL自然会走到下面这一步
            //代码再走到NULL的位置会自动进行回溯的
            inorder.push_back(root->val);
            inorderTraversal(root->right);
        }
        return inorder;
    }
    
};
//方法二: 堆栈的方法
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        if (root){
            s.push(root);
            root = root->left;
        }
        //s.push(root);
        while(!s.empty()||root){
            while(root){
                s.push(root);
                root = root->left;
            }
            auto q = s.top();
            s.pop();
            res.push_back(q->val);
            root = q->right;
            
        }
        return res;
    }
    
};