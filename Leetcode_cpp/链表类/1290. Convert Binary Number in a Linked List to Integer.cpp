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
    int getDecimalValue(ListNode* head) {
        //先遍历一遍，得到n的总数
        auto p = head;
        int sum = 0;
        int len = 1;
        while(head->next){
            head = head->next;
            len++;
        }
        //len得到这个链表总的节点数
        //auto p = head;
        if (p == NULL) return NULL;
        for(int i = len-1;i>=0;i--){
            sum += (p->val)*pow(2,i);
            p = p->next;
        }
        return sum;
    }
};