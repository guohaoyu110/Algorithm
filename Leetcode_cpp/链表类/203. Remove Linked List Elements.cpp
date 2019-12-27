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
        ListNode* dummy = new ListNode(-1);
        dummy.next = head;
        while(head->next != NULL){
            if(head->next->val == val)
                head->next = head->next->next;
            else {
                head = head->next;
            }
        }
        return dummy.next;
    }
};