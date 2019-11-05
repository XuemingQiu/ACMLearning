#include <bits/stdc++.h>

using namespace std;

/*
 * 请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
 *
 * 思路：层序遍历，用bfs，外加一个层数的奇偶性的判断即可
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
  vector<vector<int>> Print(TreeNode *pRoot)
  {
    queue<TreeNode *> q;
    vector<vector<int>> tree;
    if (pRoot == NULL)
      return tree;
    q.push(pRoot);
    int flag = 1;
    while (!q.empty())
    {
      int len = q.size();
      vector<int> tmp;
      while (len--)
      {
        TreeNode *hiretree = q.front();
        q.pop();
        tmp.push_back(hiretree->val);
        if (hiretree->left != NULL)
        {
          q.push(hiretree->left);
        }
        if (hiretree->right != NULL)
        {
          q.push(hiretree->right);
        }
      }
      if (flag % 2)
      {
        tree.push_back(tmp);
      }
      else
      {
        reverse(tmp.begin(), tmp.end());
        tree.push_back(tmp);
      }
      flag++;
    }
    return tree;
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
  auto ans = so.Print(root);
  cout << ans[0][0] << endl;
  return 0;
}

