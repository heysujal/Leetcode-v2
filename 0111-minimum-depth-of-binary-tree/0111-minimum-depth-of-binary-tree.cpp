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
    int ans = 1e9;
    void levelOrderDFS(TreeNode* root, int level) {
        if(!root)
            return;
        if(!root->left and !root->right){
            if(level < ans)
                ans = level+1;
                return;
        }
        levelOrderDFS(root->left,level+1);
        levelOrderDFS(root->right,level+1);
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        levelOrderDFS(root,0);
        return ans;
    }
};