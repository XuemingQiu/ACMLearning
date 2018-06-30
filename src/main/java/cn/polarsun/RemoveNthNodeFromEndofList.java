package cn.polarsun;

/**
 * Definition for singly-linked list. 
 * public class ListNode { 
 * 		int val; 
 * 		ListNodenext; 
 * 		ListNode(int x) { val = x; } }
 */
public class RemoveNthNodeFromEndofList {
	public ListNode removeNthFromEnd(ListNode head, int n) {
		ListNode ans = new ListNode(0);
		ListNode p = head;
		int tol = 0;
		while (p != null) {
			tol++;
			p = p.next;
		}
		int index = tol - n + 1;
		p = ans;
		tol = 0;
		while (head != null) {
			tol++;
			if (tol != index) {
				p.next = new ListNode(head.val);
				p = p.next;
			}
			head = head.next;
		}

		return ans.next;
	}
}
