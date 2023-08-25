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
    long long  prev = -2147483649;
    bool inOrder(TreeNode* root) {
        if (!root) return true;
        bool left = inOrder(root->left);
        if(prev < root->val) prev = root->val;
        else return false;
        bool right = inOrder(root->right);
        return left and right;
    }
   
    bool isValidBST(TreeNode* root) {
    std::cout<<prev << endl;
        return inOrder(root);
    }
};