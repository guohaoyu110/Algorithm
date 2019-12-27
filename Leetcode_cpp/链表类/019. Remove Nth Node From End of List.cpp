/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//这道题目可以扫描一遍，也可以扫描两遍；扫描一遍需要用两个指针！
//删除倒数第k个节点
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //这种解法就是只扫描一遍，用两个指针！
        auto p1 = head, p2 = head;
        for (int i=0;i<n;i++)
        {
            p1 = p1->next;
        }
        if (p1 == NULL) return p2->next;
        while(p1->next!=NULL)
        {
            p1 = p1->next;p2 = p2->next;
        }
        p2->next = p2->next->next;
        return head;
    }
};

//第二种方法，我不太喜欢这种方法！
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        
        ListNode* p = dummyHead;
        ListNode* cur = head;
        while(n--)
        {
            cur = cur->next;
        }
        ListNode* q = cur;
        while(q != NULL)
        {
            p = p->next;
            q = q->next;
        }
        
        ListNode* delNode = p->next;
        p->next = delNode->next;
        delete delNode;
        return dummyHead->next;
    }
};

//另外一个别人写的方法，和第一种方法比较接近
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, int k) {
        if(pListHead == NULL || k == 0){
            return NULL;
        }
        ListNode *pAhead = pListHead;
        ListNode *pBehind = pListHead;
        for(int i = 0; i < k - 1; i++){
            if(pAhead->next != NULL){
                pAhead = pAhead->next;
            }
            else{
                return NULL;
            }
        }
        while(pAhead->next != NULL){
            pAhead = pAhead->next;
            pBehind = pBehind->next;
        }
        return pBehind;
    }
};