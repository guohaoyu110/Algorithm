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
    ListNode* deleteDuplicates(ListNode* head) {
        //这个因为头结点是可能被删除的，所以必须加上一个虚拟节点
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto p = dummy;
        while(p->next){
            auto q = p->next;
            while(q&&q->val == p->next->val)
                q = q->next;
            if (p->next->next == q) p = p->next;
            else p->next = q;
        }
        return dummy->next;//同样因为头结点可能被删除所有,所以不能return head，其他情况都是没有问题的
    }
};