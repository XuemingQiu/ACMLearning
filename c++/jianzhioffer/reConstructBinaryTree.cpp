# include<bits/stdc++.h>

using namespace std;
/**
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
 * 思路： 利用深搜遍历
 */

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  TreeNode* dfs(vector<int>& pre, vector<int>& vin, int index, int end, int l,
                int r) {
    // cout << pre[index] << endl;
    if (index > end || l > r) {
      return NULL;
    }
    TreeNode* root = new TreeNode(pre[index]);
    cout << "index= " << index << ", l=" << l << " r=" << r << endl;
    for (int i = l; i <= r; ++i) {
      if (pre[index] == vin[i]) {
		//这里一定要确定好先序遍历的index指向在哪里了
        root->left = dfs(pre, vin, index + 1, index + i - l, l, i - 1);
        root->right = dfs(pre, vin, index + i - l + 1, end, i + 1, r);
        break;
      }
    }
    return root;
  }

  TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
    TreeNode* root = dfs(pre, vin, 0, pre.size() - 1, 0, vin.size() - 1);
    return root;
  }
};

void print(TreeNode* head) {
  if (head == NULL) return;
  cout << head->val << endl;
  print(head->left);
  print(head->right);
}

int main() {
  vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8};
  vector<int> vin = {4, 7, 2, 1, 5, 3, 6, 8};
  Solution so;
  TreeNode* head = so.reConstructBinaryTree(pre, vin);
  cout << "****" << endl;
  print(head);
  return 0;
}
