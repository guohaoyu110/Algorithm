/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

//不是所有的BFS都需要用queue的，依照具体情况而定
class Solution {
public:
    Node* connect(Node* root) {
    //这是一个层序的题目，是不是要用queue来做好一些
    //不需要，因为这里已经定义了next指针
        if(!root) return NULL;
        Node* last = root;
        while(last->left){//一直到叶节点
            for(auto p = last;p;p=p->next){//这个是每一行之内的操作
                p->left->next = p->right;
                if (p->next) p->right->next = p->next->left;
                else p->right->next = NULL;
            }
            last = last->left;
            //p = p->left;
        }
        return root;
    }
};