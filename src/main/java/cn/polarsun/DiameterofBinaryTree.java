package cn.polarsun;

/**
 * 
 * @author polarsun
 * 思路：树的直径就是最长的路，对于图的话，两次bfs即可，第一次bfs到达直径的一个顶点，再反向bfs找到另一个顶点
 * 而对于树来说，最长的直径就是在根的左子树的最大深度+右子树的最大深度+1就是结果。
 */

public class DiameterofBinaryTree {
//	int ans = 0;
//
//	public int diameterOfBinaryTree(TreeNode root) {
//		dfs(root);
//		return ans;
//	}
//
//	public int dfs(TreeNode root) {
//		if (root == null) {
//			return 0;
//		}
//		int leftDepth = dfs(root.left);
//		int rightDepth = dfs(root.right);
//		ans = Math.max(ans, leftDepth + rightDepth);
//		return Math.max(leftDepth, rightDepth) + 1;
//	}
}
