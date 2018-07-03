//package cn.polarsun;
//
///*
// * 典型的治题目，利用递归进行处理，使用了第21题的合并两个列表的代码
// */
///*
// * Definition for singly-linked list. public class ListNode { int val; ListNode
// * next; ListNode(int x) { val = x; } }
// */
//public class MergekSortedLists {
//	public ListNode mergeKLists(ListNode[] lists) {
//		return dfs(0, lists.length - 1, lists);
//	}
//
//	public ListNode dfs(int left, int right, ListNode[] list) {
//		if (left == right) {
//			return list[left];
//		} else if (left < right) {
//			ListNode l1 = dfs(left, (left + right) / 2, list);
//			ListNode l2 = dfs((left + right) / 2 + 1, right, list);
//			return mergeTwoLists(l1, l2);
//		} else {
//			return null;
//		}
//	}
//
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
