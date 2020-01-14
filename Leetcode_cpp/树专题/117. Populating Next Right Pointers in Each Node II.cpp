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
//通过一部分的测试用例 3/55，考虑换一种思路，如何正确的写出这道题目！
'''
class Solution {
public:
    //这个要考虑中间有节点空缺的情况，稍微复杂一点！
    Node* connect(Node* root) {
        if (!root) return NULL;
        Node* last = root;
        while(last->left){
            for (auto p = last; p ; p = p->next){
                if (p->left) p->left->next = p->right;
                if (p->next) {
                    if (p->next->left) p->right->next = p->next->left;
                    else p->right->next = p->next->right;
                }
                else p->right->next = NULL;
            }
            last = last->left;
        }
        return root;
    }
};
'''

'''
从根节点开始宽度优先遍历，每次遍历一层，从左到右依次遍历每个节点。
遍历时维护下一层节点的链表。对于每个节点，依次判断它的左儿子和右儿子是否在存在，如果存在，则插入下一层链表的末尾。
为了便于理解，我们模拟一下样例的操作流程：

第一步，遍历根节点，依次将它的左右儿子插入下一层链表，得到 2->3；
第二步，从左到右遍历第二层，即遍历 2->3，依次将它们的子节点插入下一层链表，得到 4->5->7；
第三步，遍历到叶节点层，算法结束；
时间复杂度分析：每个节点仅会遍历一次。对于每个节点，遍历时维护下一层链表的时间复杂度是 O(1)，所以总时间复杂度是 O(n)。
'''
class Solution {
public:
    Node* connect(Node* root) {
        while(root){
            Node* dummy = new Node(0);
            Node* tail = dummy;
            while(root){
                if (root->left){
                    tail->next = root->left;
                    tail = tail->next;
                }
                if (root->right){
                    tail->next = root->right;
                    tail = tail->next;
                }
                root = root->next;
            }
            tail->next = 0;
            root = dummy->next;
        }
    }
};