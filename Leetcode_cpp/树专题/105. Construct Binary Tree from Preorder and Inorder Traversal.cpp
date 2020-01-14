/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//这是二叉树的很典型的题目，从前序和中序来构造二叉树
//用递归的方法建立整课二叉树：先递归创建左右子树，然后创建根节点，并让指针指向两课子树。
//大部分这种题目都是dfs，除了最短路径相关的是BFS
'''
假设树的先序遍历是12453687，中序遍历是42516837。
这里最重要的一点就是先序遍历可以提供根的所在，而根据中序遍历的性质知道根的所在就可以将序列分为左右子树。
比如上述例子，我们知道1是根，所以根据中序遍历的结果425是左子树，而6837就是右子树。
接下来根据切出来的左右子树的长度又可以在先序便利中确定左右子树对应的子序列（先序遍历也是先左子树后右子树）。
根据这个流程，左子树的先序遍历和中序遍历分别是245和425，右子树的先序遍历和中序遍历则是3687和6837，我们重复以上方法，
可以继续找到根和左右子树，直到剩下一个元素。可以看出这是一个比较明显的递归过程，对于寻找根所对应的下标，我们可以先建立一个HashMap，
以免后面需要进行线行搜索，这样每次递归中就只需要常量操作就可以完成对根的确定和左右子树的分割。

'''
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pl = preorder[0], pr = preorder[preorder.size()-1];
        int il = inorder[0] , ir = inorder[inorder.size()-1];
        dfs(preorder,inorder,pl,pr,il,ir);
    }
    TreeNode* dfs(vector<int>&pre, vector<int>&in, int pl, int pr, int il, int ir){
        //先根据先序遍历的第一个数字来判断，将中序序列分成左子树和右字数。

    }
};