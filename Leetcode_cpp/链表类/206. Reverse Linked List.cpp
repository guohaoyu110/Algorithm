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
    ListNode* reverseList(ListNode* head) {
        //auto dummy = new ListNode(-1);
        ListNode *prev = NULL;
        while(head !=NULL)
        {
            //temp记录下一个节点，head是当前节点
            ListNode * tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        return prev;

    }
};