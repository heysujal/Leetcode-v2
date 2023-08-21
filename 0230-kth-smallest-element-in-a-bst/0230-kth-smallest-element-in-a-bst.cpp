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
    int ans;
    void inorder(TreeNode* root, int &count, int k){
        if(!root) return;
        inorder(root->left, count, k);
        count++;
        if(count == k){
            ans = root->val;
            return;
        } 
        inorder(root->right, count, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        inorder(root, count, k);
        return ans;
    }
};