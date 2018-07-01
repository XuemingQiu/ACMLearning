//package cn.polarsun;
//
///**
// * Definition for singly-linked list. public class ListNode { int val; ListNode
// * next; ListNode(int x) { val = x; } }
// */
//public class MergeTwoSortedLists {
//	public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
//		ListNode ans = new ListNode(0);
//		ListNode head = ans;
//		while (l1 != null && l2 != null) {
//			if (l1.val <= l2.val) {
//				ans.next = new ListNode(l1.val);
//				l1 = l1.next;
//				ans = ans.next;
//			} else {
//				ans.next = new ListNode(l2.val);
//				l2 = l2.next;
//				ans = ans.next;
//			}
//		}
//		while (l1 != null) {
//			ans.next = new ListNode(l1.val);
//			l1 = l1.next;
//			ans = ans.next;
//		}
//		while (l2 != null) {
//			ans.next = new ListNode(l2.val);
//			l2 = l2.next;
//			ans = ans.next;
//		}
//		return head.next;
//	}
//}
