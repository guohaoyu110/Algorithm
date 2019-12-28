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
        ListNode *prev = NULL; //prev 表示前继节点
        while(head !=NULL)
        {
            //temp记录下一个节点，head是当前节点
            ListNode * tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
            //这个思维还是精巧的，多看看这道题目！
        }
        
        return prev;

    }
};