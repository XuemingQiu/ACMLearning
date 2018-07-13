//package cn.polarsun;
//
//public class ValidateBinarySearchTree {
//	/*
//	 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
//	 * left; TreeNode right; TreeNode(int x) { val = x; } }
//	 */
//	TreeNode pre;
//
//	public boolean isValidBST(TreeNode root) {
//		if (root == null) {
//			return true;
//		}
//		if (!isValidBST(root.left)) {
//			return false;
//		}
//		if (pre != null && pre.val >= root.val) {
//			return false;
//		}
//		pre = root;
//		return isValidBST(root.right);
//
//	}
//}
