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
    vector<int> in;
    void inOrder(TreeNode* root) {
        if (!root)
            return;
        inOrder(root->left);
        in.push_back(root->val);
        inOrder(root->right);
    }
   
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        inOrder(root);
        for(int i = 1; i < in.size(); i++)
            if(in[i] <= in[i-1])
                return false;
        return true;
    }
};