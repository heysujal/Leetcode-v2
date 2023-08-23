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
        if(!p or !q) return p ? p : q;
        p->val += q->val;
        p->left = mergeTrees(p->left, q->left);
        p->right = mergeTrees(p->right, q->right);
        return p;
    }
};