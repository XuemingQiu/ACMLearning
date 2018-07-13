//package cn.polarsun;
//
//public class ValidateBinarySearchTree {
//	/**
//	 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
//	 * left; TreeNode right; TreeNode(int x) { val = x; } }
//	 */
//	int min = Integer.MIN_VALUE;
//	boolean flag = true;
//	int k = 1;
//
//	public boolean isValidBST(TreeNode root) {
//		dfs(root);
//		return flag;
//	}
//
//	void dfs(TreeNode root) {
//		if (root == null) {
//			return;
//		}
//		dfs(root.left);
//		if (k == 1) {
//			k++;
//		} else if (min >= root.val) {
//			flag = false;
//		}
//		min = root.val;
//		dfs(root.right);
//	}
//}
