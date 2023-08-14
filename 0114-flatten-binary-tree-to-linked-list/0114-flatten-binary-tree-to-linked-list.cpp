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
    void preOrder(TreeNode* root, vector<TreeNode*> &preorder){
        if(!root)
            return;
        preorder.push_back(root);
        preOrder(root->left, preorder);
        preOrder(root->right, preorder);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> preorder;
        preOrder(root, preorder);
        TreeNode* curr = new TreeNode();
        TreeNode* aux = curr;
        for(int i = 0; i < preorder.size(); i++){
            curr->right = preorder[i];
            curr->left = NULL;
            curr = curr->right;
        }
        root = aux->right;
    }
};