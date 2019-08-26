#include <bits/stdc++.h>
/**
 * 题目大意，让你删除所有链表的所有和为0的节点，保留最后剩下的
 * 思路：以一个节点为起点，找到和为0的最后的节点，跳转过去即可
 * ps：
 *    这里为了理解方便，使用了数组存数，可以直接用了链表串起来的
 */
using namespace std;

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* p1=head;

        vector<int>ans;
        while(p1 != NULL){
            ListNode*p2=p1->next;
            int sum = p1->val;
            ListNode*tmp=p2;
            if(sum == 0){
                p1 = p2;
                continue;
            }
            bool flag = 0;
            while(p2 != NULL){
                sum += p2->val;
                p2 = p2->next;
                if(sum == 0){
                    tmp = p2;
                    flag = 1;
                }
            }
            if(!flag){
                ans.push_back(p1->val);
            }
            p1 = tmp;
        }
        if(ans.size() == 0){
            return NULL;
        }
        ListNode* root = new ListNode(ans[0]);
        ListNode* rt = root;
        for(int i = 1;i < ans.size();++i){
            ListNode* tp =  new ListNode(ans[i]);
            rt->next = tp;
            rt = rt->next;
        }
        return root;
    }
};

int main(){
	return 0;
}
