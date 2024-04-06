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
    long  prev = LONG_MIN;
    bool inOrder(TreeNode* root) {
        if (!root) return true;
        bool left = inOrder(root->left);
        if(prev < root->val) prev = root->val;
        else return false;
        bool right = inOrder(root->right);
        return left and right;
    }
    
    bool isValidBST(TreeNode* root) {
        prev = LONG_MIN;
        return inOrder(root);
    }
    
    int sumOfNodes(TreeNode* root){
        return !root ? 0 : root->val + sumOfNodes(root->left) + sumOfNodes(root->right);
    }
    int maxSumBST(TreeNode* root) {
        if(!root) return 0;
        int sum = INT_MIN;
        if(isValidBST(root)){
            sum = sumOfNodes(root);
            sum = sum < 0 ? 0 : sum;
        }
    	int left = maxSumBST(root->left);
    	int right = maxSumBST(root->right);
        return max(sum, max(left, right));
    }
};