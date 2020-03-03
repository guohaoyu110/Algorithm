/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//reverse函数这个要当做常态化的处理，因为实在太常用了！
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //auto dummy = new ListNode(-1);
        ListNode *prev = nullptr; //prev 表示前继节点
        while(head != nullptr){
            //temp记录下一个节点，head是当前节点
            ListNode * tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
            //这个思维还是精巧的，多看看这道题目！
        }
        
        return prev;

    }
};
 
// 20200302
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur){
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
        //prev到末尾节点的时候，返回头结点prev
        //因为cur形成了这个指针联系关系，prev实际相当于cur的位置
    }
};