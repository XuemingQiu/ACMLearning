#include <bits/stdc++.h>

using namespace std;
/*
 * 题目大意: 输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)
 * 思路： 深搜判断出那些满足和的路径，然后对最后的结果进行排序即可
 *
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
    void dfs(TreeNode *root, int sum, vector<int> path, vector<vector<int>> &ans)
    {
        if (root->left == NULL && root->right == NULL && sum == 0)
        {
            ans.push_back(path);
            return;
        }
        if (root == NULL)
        {
            return;
        }
        if (root->left != NULL)
        {
            path.push_back(root->left->val);// 暂存路径
            dfs(root->left, sum - root->left->val, path, ans);
            path.erase(path.end() - 1);
        }
        if (root->right != NULL)
        {
            path.push_back(root->right->val);
            dfs(root->right, sum - root->right->val, path, ans);
            path.erase(path.end() - 1);
        }
    }
    vector<vector<int>> FindPath(TreeNode *root, int expectNumber)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        vector<int> path;
        path.push_back(root->val);
        dfs(root, expectNumber - root->val, path, ans);
        int len = ans.size();
		// 排序
        for (int i = 0; i < len; ++i)
        {
            for (int j = i + 1; j < len; ++j)
            {
                if (ans[i].size() < ans[j].size())
                {
                    swap(ans[i], ans[j]);
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution so;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(1);
    root->right->right->left = new TreeNode(1);

    vector<vector<int>> ans = so.FindPath(root, 5);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

