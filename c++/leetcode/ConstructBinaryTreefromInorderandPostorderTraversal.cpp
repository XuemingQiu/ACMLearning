#include<bits/stdc++.h>


using namespace std;
/**
 * 给定中序和后序遍历，让你构建二叉树
 *
 * 和 给定先序和中序，求二叉树的区别在与，dfs写的时候，后者更新的left-1，前者更新的right-1
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder,int ileft,int iright,int pleft,int pright){
        if(ileft>iright || pleft > pright) return NULL;
        int i = 0;
        // cout << "&&&&& " << postorder[pright] << endl;
        for(i = ileft; i <= iright; ++i){
            // cout << inorder[i] << " ";
            if(inorder[i] == postorder[pright]){
                break;
            }
        }
        // cout << endl <<  "iiiiiiiiii " << inorder[i] <<endl;
        TreeNode* root = new TreeNode(postorder[pright]);
        int len = i-ileft;
        root->left = dfs(inorder,postorder,ileft,i-1,pleft,pleft+len-1);
        root->right = dfs(inorder,postorder,i+1,iright,pleft+len,pright-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return dfs(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
};

int main(){
	return 0;
}
