//package cn.polarsun;
//
///*
// * Definition for singly-linked list.
// * public class ListNode {
// *     int val;
// *     ListNode next;
// *     ListNode(int x) { val = x; }
// * }
// */
//public class SwapNodesinPairs {
//	public ListNode swapPairs(ListNode head) {
//		ListNode p = head;
//		ListNode pre = head;
//		head = head != null && head.next != null ? head.next : head;
//		while (p != null && p.next != null) {
//			if (pre != head) {
//				pre.next = p.next;
//			}
//			System.out.println("swap " + p.val + " " + p.next.val);
//			swapTwoNode(p, p.next);
//			pre = p;
//			p = p.next;
//
//		}
//		return head;
//	}
//
//	public void swapTwoNode(ListNode a, ListNode b) {
//		a.next = b.next;
//		b.next = a;
//	}
//}
