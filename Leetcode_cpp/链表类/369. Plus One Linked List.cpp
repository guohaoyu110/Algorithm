/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//这道题目特别棒，各种因素都要考虑到，特别考验思维！
class Solution {
private:
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
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
public:
    ListNode* plusOne(ListNode* head) {
        if (head == NULL) return NULL;
        auto newHead = reverse(head);
        auto dummy = newHead;
    
        int carry = 1;
        while(newHead){
            int temp = carry + newHead->val;
            carry = temp/10;
            newHead->val = temp%10;
            newHead = newHead->next;
        }
        if (carry!=0){
            auto newNode = new ListNode(1);
            head->next = newNode;
        }
        return reverse(dummy);
    }
};