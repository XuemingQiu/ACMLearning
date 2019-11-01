#include<bits/stdc++.h>

using namespace std;
/*
 * 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
 * 思想很简单，一种深搜迭代，一种是比较while合并，这块分两步比较
 */
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
      if(pHead1 == NULL) return pHead2;
      if(pHead2 == NULL) return pHead1;
      if(pHead1->val <= pHead2->val){
        ListNode* p = pHead1;
        while(p->next != NULL && pHead2 != NULL){
          if(p->next->val <= pHead2->val){
            p = p->next;
          }else{
            ListNode* q = pHead2->next;
            pHead2->next = p->next;
            p->next = pHead2;
            p = pHead2;
            pHead2 = q;
          }
        }
        if(pHead2 != NULL){
          p->next = pHead2;
        }
        return pHead1;
      }
      ListNode* p = pHead2;
      while(p->next != NULL && pHead1 != NULL){
        if(p->next->val <= pHead1->val){
          p = p->next;
        }else{
          ListNode* q = pHead1->next;
          pHead1->next = p->next;
          p->next = pHead1;
          p = pHead1;
          pHead1 = q;
        }
      }
      if(pHead1 != NULL){
        p->next = pHead1;
      }
      return pHead2;
    }
      
};


class Solution2 {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
      if(pHead1 == NULL) return pHead2;
      if(pHead2 == NULL) return pHead1;
      ListNode* head = NULL;
      if(pHead1->val < pHead2->val){
        head = pHead1;
        head->next = Merge(pHead1->next,pHead2);
      }else{
        head = pHead2;
        head->next = Merge(pHead1,pHead2->next);
      }
      return head;
    }
};


int main(){
	return 0;
}
