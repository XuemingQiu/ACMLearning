package cn.polarsun;
class ConvertBSTtoGreaterTree{
    int temp = 0;
    public TreeNode convertBST(TreeNode root) {
        dfs(root);
        return root;
    }
    private void dfs(TreeNode root){
        if(root == null){
            return;
        }
        dfs(root.right);
        // System.out.println(temp+ " :" + root.val);
        root.val += temp;
        temp = root.val;
        dfs(root.left);
    }
}
