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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        //这道题目肯定要用双指针了
        //时间复杂度分析：整个链表只遍历了一遍，所以时间复杂度是 O(n)O(n)。
        if (m==n) return head;

        
    }
};