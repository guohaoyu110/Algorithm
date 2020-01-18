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
//方法一：一层一层的来做这件事情，这个是典型的用递归的方法
//为什么这个是先connect(root->right) 然后 connect(root->left)
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        Node * node = root->next;
        while(node){
            if(node->left){
                node = node->left;
                break;
            }
            else if (node->right){
                node = node->right;
                break;
            }
            else {
                node = node->next;
            }
        }
        if (root->left && root->right){
            root->left->next = root->right;
            root->right->next = node;
        }
        else if (!root->left && root->right) root->right->next = node;
        else if (root->left&&!root->right) root->left->next = node;
        connect(root->right);
        connect(root->left);
        return root;     
    }
};

//方法二：用队列的方法，迭代的方法
'''
队列是为了维护先后关系
但是先后关系本来就存在了next里
所以可以不使用队列
'''
class Solution {
public:
    Node* connect(Node* root) {
        if (!root)  return NULL;
        queue q;
        q.push(root);
        while(!q.empty()){
            Node* cur = NULL;
            int size = q.size();
            //for(int i =0)
        }  
    }
};

//方法三，使用next指针来代替队列，不用queue
Node* connect(Node* root) {
        Node *last = root;
        while(last != NULL){
            // 获得队首元素
            while(last && last->left == NULL && last->right == NULL)last = last->next;
            if(last == NULL)break;
            Node *cur = NULL;
            // 遍历队列
            for(Node *i = last;i != NULL;i = i->next){
                // 进行push和pop操作
                if(i -> left){
                    if(cur != NULL){
                        cur->next = i->left;
                    }
                    cur = i->left;
                }
                if(i -> right){
                    if(cur != NULL){
                        cur->next = i->right;
                    }
                    cur = i->right;
                }
            }
            // 更新队首
            last = last->left ? last->left : last->right;
        }
        return root;
    }

