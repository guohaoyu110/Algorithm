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
    bool isPalindrome(ListNode* head) {
        //和链表206题相对应起来看，关于链表翻转的问题
        if (head == NULL) return true;
        auto p = head;
        int len = 1;
        while(p->next){
            p = p->next;
            len ++;
        }
        //要不要分时偶数和奇数的情况
        if (len == 1) return true;
        //把后半段进行翻转，然后和前半段逐一对比
        int len2;
        if(len % 2 == 0) len2 = len / 2;
        else len2 = (len + 1) / 2;
        
        p = head;
        for(int i = 1; i <= len2; ++i)
            p = p->next;

        ListNode* prev = nullptr; // 从p出开始断开，翻转
        while(p)
        {
            //tmp记录下一个节点，p是当前节点
            ListNode* tmp = p->next;
            p->next = prev;
            prev = p;
            p = tmp;
        }
        // 前后段比较
        p = head;
        while(prev != NULL && p != NULL) // 后半段与前半段比，要么相等，要么短一个长度
        {
            if(prev->val != p->val) return false;
            prev = prev->next;
            p = p->next;
        }
        return true;

    }
};