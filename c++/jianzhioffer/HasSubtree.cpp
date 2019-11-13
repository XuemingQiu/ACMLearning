#include <bits/stdc++.h>

using namespace std;

/*
 * 题目：输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
 * 思路：判断根节点是不是相同，相同就是要求左右一样。不同就分开去计算。
 *
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
  bool judge(TreeNode *root1, TreeNode *root2)
  {
    if (root2 == NULL)
      return true;
    if (root1 == NULL)
      return false;

    if (root1->val == root2->val)
    {
      return judge(root1->left, root2->left) && judge(root1->right, root2->right);
    }
    else
    {
      return judge(root1->left, root2) || judge(root1->right, root2);
    }
  }
  bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
  {
    if (pRoot2 == NULL || pRoot1 == NULL)
      return false;
    return judge(pRoot1, pRoot2) || judge(pRoot1->left, pRoot2) || judge(pRoot1->right, pRoot2);
  }
};

int main(){
	return 0;
}
