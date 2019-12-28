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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto res = new ListNode(-1);//添加虚拟头结点，简化边界判定情况
        auto cur = res;
        int carry = 0;//表示进位
        while(l1||l2){
            int n1 = l1?l1->val:0;
            int n2 = l2?l2->val:0;
            int sum = n1+n2+carry;
            cur->next = new ListNode(sum%10);
            carry = sum/10;
            cur = cur->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry) cur->next = new ListNode(1);
        return res->next;

    }
};