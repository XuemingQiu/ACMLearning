package cn.polarsun;

/***
 * 
 * @author polarsun
 *  思路：先序遍历，然后查看每个节点，它的的子树满不满足要求,问题呗分解成求解子树的过程
 */
public class PathSumIII {
//	public int pathSum(TreeNode root, int sum) {
//        if(root == null){
//            return 0;
//        }
//        return findPath(root,sum)+pathSum(root.left,sum)+pathSum(root.right,sum);
//    }
//    public int findPath(TreeNode root, int sum){
//        int t = 0;
//        if(root == null){
//            return t;
//        } 
//        if(sum == root.val){
//            t++;
//        }
//        t += findPath(root.left,sum-root.val);
//        t += findPath(root.right,sum-root.val);
//        return t;
//    }
}
}
