#include <bits/stdc++.h>

using namespace std;
/*
 * 请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
 * 思路：每次左子树的左节点和右子树的右节点比，左子树的右节点和右子树的左节点比较，不断的深搜过程
 */
struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL)
  {
  }
};
class Solution
{
public:
  bool isSymmetrical(TreeNode *pRoot)
  {
    if (pRoot == NULL)
    {
      return true;
    }
    return judge(pRoot->left, pRoot->right);
  }
  bool judge(TreeNode *left, TreeNode *right)
  {
    if (left == NULL && right == NULL)
      return true;
    if (left == NULL || right == NULL)
      return false;
    if (left->val != right->val)
      return false;
    return judge(left->left, right->right) && judge(left->right, right->left);
  }
};

int main()
{
  TreeNode *root = new TreeNode(1);
  TreeNode *p = root;
  p->left = new TreeNode(3);
  p->right = new TreeNode(3);
  p = p->left;
  p->right = new TreeNode(10);
  p->left = new TreeNode(10);
  Solution so;
  auto ans = so.isSymmetrical(root);
  cout << ans << endl;
  return 0;
}

