/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int n = 0;
        for(auto p = head;p;p = p->next) n++;
        auto dummy = new ListNode(-1);
        
    }
};