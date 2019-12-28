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
//这个肯定是要两个指针的，一个快指针，一个慢指针
//时间复杂度分析：链表一共遍历2遍，所以总时间复杂度是 O(n)O(n)。
//这道题目还是要很小心的！
    ListNode* rotateRight(ListNode* head, int k) {
        //这个没有必要创建一个虚节点
        if (head == NULL) return head;
        auto p = head;
        int n = 0;
        while(p){
            n++;
            p = p->next;
        }
        if (!k) return head;
        k = k%n;

        auto first = head;
        while(k--&&first) first = first->next;
        auto second = head;

        while(first->next){
            first = first->next;
            second = second->next;
        }
        first->next = head;
        head = second->next;
        second->next = NULL;


        return head;
    }
};