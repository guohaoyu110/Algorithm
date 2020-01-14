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
//方法一：这个思路还是非常简洁明了的
class Solution {
public:
    vector<int> get_val(vector<TreeNode*> level)
    {
        vector<int> res;
        for (auto &u : level)
            res.push_back(u->val);
        return res;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;//这里是用数组代替队列了，如果用队列的话应该怎么写呢？看下面的解法
        if (!root) return res;
        vector<TreeNode*>level;//存储了这个整棵树
        level.push_back(root);
        res.push_back(get_val(level));
        while(true){
            //while(true)在这里是必须的
            vector<TreeNode*>newlevel;
            for(auto u :level){
                if (u->left) newlevel.push_back(u->left);
                if (u->right) newlevel.push_back(u->right);
            }
            if (newlevel.size()){
                res.push_back(get_val(newlevel));
                level = newlevel;
            }
            else break;
        }
        return res;
    }
};


//方法二：用队列的方法

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
    void bfs(TreeNode* root,vector<vector<int>>& res){
        queue<TreeNode*>s;//S是一个队列，先进先出，里面存的是指针类型
        //定义一个队列，数据类型是树的类型
        s.push(root);//将头结点添加到队列
        s.push(NULL);
        while(s.front()){//每一层都要建立一个新的vector数组
            vector<int>t;
            auto p = s.front();s.pop();//取出节点
            while(p){
                t.push_back(p->val);
                if (p->left) s.push(p->left);
                if (p->right) s.push(p->right);
                p=s.front();s.pop();//取出该层所有节点
            }
            s.push(NULL);
            res.push_back(t);

        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        bfs(root,res);
        return res;
    }
};