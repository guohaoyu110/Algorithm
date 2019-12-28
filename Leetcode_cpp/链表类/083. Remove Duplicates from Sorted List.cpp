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
        if (head == NULL) return NULL;//因为没有构造一个虚拟节点，所以开头需要判断一下。
        auto node = head;
        //delete duplicates因为是从原来的链表里面删除一个元素，所以不需要重新构造一个节点。但是应该也可以
        while(node->next!=NULL){
            if (node->val == node->next->val)
                node->next = node->next->next;
            else
                node = node->next;
        }

        return head;
    }
    //return head;
};