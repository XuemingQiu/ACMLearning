package cn.polarsun;

//public class ListNode {
//	int val;
//	ListNode next;
//	ListNode(int x) {
//		val = x;
//	}
//}
public class AddTwoNumbers {
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int flag = 0;
        ListNode ans = new ListNode(0);
        ListNode head = ans;
        while(l1!=null && l2!=null){
            int s = l1.val+l2.val+flag;
            flag = s/10;
            ListNode temp = new ListNode(s%10);
            ans.next = temp;
            ans = temp;
            l1 = l1.next;
            l2 = l2.next;
        }
        while(l1!=null){
            int s = l1.val+flag;
            flag = s/10;
            ListNode temp = new ListNode(s%10);
            ans.next = temp;
            ans = temp;
            l1 = l1.next;
        }
          while(l2!=null){
            int s = l2.val+flag;
            flag = s/10;
            ListNode temp = new ListNode(s%10);
            ans.next = temp;
            ans = temp;
            l2 = l2.next;
        }
        if(flag!=0){
            ListNode temp = new ListNode(flag);
            ans.next = temp;
            ans = temp;
        }
        return head.next;
    }
}
