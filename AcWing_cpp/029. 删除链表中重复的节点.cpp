/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//这道题目还是值得思考的，为什么需要两个指针，为什么一个指针是不可以的？
//
class Solution {
public:
    ListNode* deleteDuplication(ListNode* head) {
        auto p = new ListNode(-1);
        p->next = head;
        while(p->next){
            if (p->next->val == p->next->next->val)
                p->next = p->next->next;
            else p = p->next;
        }
        return head;
    }
};