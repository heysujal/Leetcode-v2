/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertInBST(TreeNode* root, int x){
        if(!root) return new TreeNode(x);
        if(x < root->val)
            root->left = insertInBST(root->left, x);
        else
            root->right = insertInBST(root->right, x);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i = 1; i < n; i++){
            insertInBST(root, preorder[i]);
        }
        return root;
    }
};