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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto p1 = headA;
        auto p2 = headB;
        if (!p1||!p2) return NULL;
        int len1=1, len2=1;
        while(p1->next){
            p1 = p1->next;
            len1++;
        }
        while(p2->next){
            p2 = p2->next;
            len2++;
        }
        if (p1!=p2) return NULL;

        if (len1 > len2){
            for(int i=0;i<len1-len2;i++)
                headA = headA->next;
        }
        else if (len2 > len1){
            for(int i=0;i<len2-len1;i++)
                headB = headB->next;
        }
        while(headA!=headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;


    }
};