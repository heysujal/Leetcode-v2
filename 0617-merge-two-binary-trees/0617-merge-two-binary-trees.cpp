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
    TreeNode* mergeTrees(TreeNode* p, TreeNode* q) {
        if(p and q){
            TreeNode *root = new TreeNode(p->val + q->val);
            root->left = mergeTrees(p->left, q->left);
            root->right = mergeTrees(p->right, q->right);
            return root;
        }else{
            return p ? p : q;
        }
    }
};