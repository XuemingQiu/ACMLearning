package cn.polarsun;

/**
 * 
 * @author polarsun
 * 思路：判断s的每一棵字数是否和t相同，直接树的搜索
 */
public class SubtreeofAnotherTree {
//	public boolean isSubtree(TreeNode s, TreeNode t) {
//		if (t == null) {
//			return true;
//		}
//		if (s == null) {
//			return false;
//		}
//		if (isSame(s, t)) {
//			return true;
//		}
//		return isSubtree(s.left, t) || isSubtree(s.right, t);
//	}
//
//	public boolean isSame(TreeNode s, TreeNode t) {
//		if (s == null && t == null) {
//			return true;
//		}
//		if (s != null && t != null && s.val == t.val) {
//			return isSame(s.left, t.left) && isSame(s.right, t.right);
//		}
//		return false;
//	}
}
