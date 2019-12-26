/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//这个有点类似于归并排序那种
//不需要先合并，然后再排序；可以用两个指针，先指着开头的位置，这个复杂度是线性的！
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //需要一个cur指针去记住当前链表的尾节点在哪里
        auto dummy = new ListNode(-1);
        auto cur = dummy;
        while(l1&&l2){
            if (l1->val<l2->val)
            {
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
        }
        if (l1)
            cur->next = l1;
        else cur->next = l2;

        return dummy->next;//新的链表的头结点就是虚拟头结点的next的位置。
    }
};