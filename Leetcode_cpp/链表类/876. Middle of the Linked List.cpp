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
    ListNode* middleNode(ListNode* head) {
        //这个还是一个快指针，一个慢指针的方法
        auto first = head;
        auto second = head;
        while (first&& first->next) {
            //slow = slow->next;
            //fast = fast->next->next;
            second = second->next;
            first = first->next->next;
        }
        return second;
    }
};