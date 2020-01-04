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
    ListNode* swapPairs(ListNode* head) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto cur = dummy;
        while(cur!=NULL){
            ListNode* first = cur->next;
            if (first == NULL)
                break;
            ListNode* second = first->next;
            if (second == NULL)
                break;
            //按照一定的次序，交换相临的两点
            //用三个点来实现这个每两个点之间的互换
            cur->next = second;
            first->next = second->next;
            second->next = first;

            cur = first;
        }
        return dummy->next;  //比如head是1，但是head在这个里面是第二个节点
    }
};