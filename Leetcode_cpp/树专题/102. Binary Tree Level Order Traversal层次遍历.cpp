/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//肯定是用BFS的方法来做层次遍历
'''
算法
(BFS) O(n)
宽度优先遍历，一层一层来做。即：

1. 将根节点插入队列中；
2. 创建一个新队列，用来按顺序保存下一层的所有子节点；
3. 对于当前队列中的所有节点，按顺序依次将儿子加入新队列，并将当前节点的值记录在答案中；
4. 重复步骤2-3，直到队列为空为止。

时间复杂度分析：树中每个节点仅会进队出队一次，所以时间复杂度是 O(n) 。
'''
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        vector<TreeNode*>level;
        level.push_back(root);
        res.push_back()
        while(true){
            vector<TreeNode*>newlevel;
            for(auto u :level){
                if (u->left) newlevel.push_back(u->left);
                if (u->right) newlevel.push_back(u->right);
            }
            if (newlevel.size()){
                res.push_back()
                level = newlevel;
            }
            else break;
        }
        return res;
    }
};