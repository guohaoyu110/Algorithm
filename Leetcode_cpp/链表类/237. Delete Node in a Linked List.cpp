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
        //把当前的node完全变成下一个node， 一个ListNode包含就两个变量，都改成下一个的值就可以了
        if (node == NULL)
            return;
        if (node->next == NULL){
            node = NULL;
            return;
        }
        node->val = node->next->val;
        node->next = node->next->next;

        //return;
    }
    return;
};