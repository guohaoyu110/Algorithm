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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return head;
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto p = dummy;
        while(p->next!=NULL){
            if (p->next->val == val)
                p->next = p->next->next;
            else
            {
                p = p->next;
            }
            
        }
        return dummy->next;
    }
};