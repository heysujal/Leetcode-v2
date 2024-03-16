/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        if (!root) return ret;
        
        leftRet = inorderTraversal(root->left);
        ret.insert(ret.end(), leftRet.begin(), leftRet.end());
        
        ret.push_back(root->value);
        
        rightRet = inorderTraversal(root->right);
        ret.insert(ret.end(), rightRet.begin(), rightRet.end());
        
        return ret;
    }
};