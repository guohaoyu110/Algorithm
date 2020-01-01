/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//为什么这个return p就能返回一个节点，而不是一个链表串呢？
// 
class Solution {
public:
    ListNode* FindKthToTail(ListNode* head, int k) {
        int n = 0;
        for (auto p = head; p; p = p->next) n ++ ;
        if (n < k) return NULL;
        auto p = head;
        for (int i = 0; i < n - k; i ++ ) p = p->next;
        return p;
    }
};