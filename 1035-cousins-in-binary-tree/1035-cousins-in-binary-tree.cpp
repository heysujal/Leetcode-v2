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
    TreeNode* findNode(TreeNode* root, int x){
        if(!root) return nullptr;
        if(root->val == x) return root;
        auto left = findNode(root->left, x);
        if(left) return left;
        return findNode(root->right, x);
    }
    int level(TreeNode* root, TreeNode* target, int lvl){
        if(!root) return 0;
        if(root == target) return lvl;
        int l = level(root->left, target, lvl+1);
        if(l != 0)
            return l;
        return level(root->right, target, lvl+1);
    }
    bool isSibling(TreeNode* root, TreeNode* x, TreeNode* y){
        if(!root) return false;
        return (root->left == x and root->right == y || root->right == x and root->left == y)
                or isSibling(root->left,x, y) 
                or isSibling(root->right,x,y);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode* xx = findNode(root, x);
        TreeNode* yy = findNode(root, y);
        return level(root, xx, 0) == level(root, yy, 0) and !isSibling(root, xx, yy);
    }
};