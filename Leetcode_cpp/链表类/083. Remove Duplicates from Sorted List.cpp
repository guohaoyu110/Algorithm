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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return NULL;
        auto node = head;
        while(node->next!=NULL){
            if (node->val == node->next->val)
                node->next = node->next->next;
            else
                node = node->next;
        }

        return head;
    }
    //return head;
};