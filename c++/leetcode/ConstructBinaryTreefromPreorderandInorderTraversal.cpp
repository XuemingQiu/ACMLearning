#include <bits/stdc++/h>

using namespace std;

/**
 * 根据前序和中序遍历，构建这颗树
 */


class Solution {
public:
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder,int pleft,int pright, int left,int right){
        if(pleft>pright || left>right) return NULL;
        int i = 0;
        for(i=left;i<=right;++i){
            if(preorder[pleft]==inorder[i]) break;
        }
        int len = i-left;
        TreeNode *root = new TreeNode(preorder[pleft]);
        root->left = dfs(preorder,inorder,pleft+1,pleft+len,left,i-1);
        root->right = dfs(preorder,inorder,pleft+len+1,pright,i+1,right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};


int main(){
	return 0;
}
