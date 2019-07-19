/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * 题目意思很简单，给你两棵树，树定义了一种翻转操作，可以交换左右子树，让你判断交换部分子树后两棵树相不相等 
 * 思路：很简单的题目，然而我现在忘得差不多了，
 *       直接思维，我每次判断节点不同时，我就交换第一个树的左右子树，再去判断是否和第二个树相等
 *       后来看到了这种解放，不要去交换操作，而是分成两种情况，第一棵的左子树和第二棵的左，右和右比； 或者第一棵右和第二棵左比，左和右比即可
 *
 */
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL){
            return true;
        }else if((root1==NULL&&root2!=NULL) || (root1!=NULL&&root2==NULL) || (root1->val!=root2->val)){
            return false;
        }
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) || (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    
    }
};
