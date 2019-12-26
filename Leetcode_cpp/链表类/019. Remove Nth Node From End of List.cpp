/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//这道题目可以扫描一遍，也可以扫描两遍；扫描一遍需要用两个指针！
//删除倒数第k个节点
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //这种解法就是只扫描一遍，用两个指针！
        auto p1 = head, p2 = head;
        for (int i=0;i<n;i++)
        {
            p1 = p1->next;
        }
        if (p1 == NULL) return p2->next;
        while(p1->next!=NULL)
        {
            p1 = p1->next;p2 = p2->next;
        }
        p2->next = p2->next->next;
        return head;
    }
};