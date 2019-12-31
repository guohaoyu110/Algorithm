/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        //删除node这个节点，并且node一定不是尾节点
        auto p = node->next;
        
        node->val = p->val;//这个不是指针，只是简单的赋值
        node->next = p->next;
        // 这两步的作用就是将 *(node->next) 赋值给 *node，所以可以合并成一条语句：
        // *node = *(node->next);

        delete p;//做不做都行，最好删掉p指针
    }
};