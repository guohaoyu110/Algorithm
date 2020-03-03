class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow, *fast;
        if(head == nullptr || head->next == nullptr)
            return false;
        //slow = head; fast = head;
        fast = head->next->next; slow = head->next;

        while(fast!=slow){
            if (fast == nullptr|| fast->next == nullptr){
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;

        }
        return true;
    }
};