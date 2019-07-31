#include <bits/stdc++.h>

using namespace std;
/*
 * 题目意思：给定一个二叉树，每个节点的值不同，删除一些节点，返回剩下的森林
 * 思路：遍历每一个节点，如果该节点的值在要删除的里面，那么就遍历其子树，然后将该点置空
 * 深搜的时候，带一个标志来进行标注该点是不是加入到答案中了，后序遍历存进答案！
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*>ans;

    void dfs(TreeNode* &root,vector<int>& to_delete,bool flag){
         if(root==NULL){
            return;
         }
         if(find(to_delete.begin(),to_delete.end(),root->val) != to_delete.end()){
            dfs(root->left,to_delete,true);
            dfs(root->right,to_delete,true);
            root=NULL;
         } else{
            dfs(root->left,to_delete,false);
            dfs(root->right,to_delete,false);
            if(flag){
                ans.push_back(root);
            }
         }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        dfs(root,to_delete,true);
        return ans;
    }
};

int main(){
    return 0;
}

