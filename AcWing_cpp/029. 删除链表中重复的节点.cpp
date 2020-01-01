/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//这道题目还是值得思考的，为什么需要两个指针，为什么一个指针是不可以的？
// 因为隐藏掉的那个部分只能跳过一个值，不能跳过两个连续的值
'''
    while(p->next){
        if (p->next->val == p->next->next->val)                
            p->next = p->next->next;//用这种方法只能跳过一个数值，不能跳过两个连续的数值
        else p = p->next;
    }
'''
//链表题目一定要在纸上画清楚，想清楚每一个的过程！
class Solution {
public:
    ListNode* deleteDuplication(ListNode* head) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto p = dummy;
        while(p->next){
            auto q = p->next;
            while(q&&p->next->val == q->val) q = q->next;
            if (p->next->next == q) p = p->next;
            else p->next = q;

        }
        return dummy->next;
    }
};
