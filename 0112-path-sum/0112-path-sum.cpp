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

    bool solve(TreeNode *root, int mySum , int &targetSum)
    {

        if(!root)
            return false;
        
        if(!root->left and !root->right)
        {   mySum += root->val;
            if(mySum == targetSum)  
                return 1;
            
            return 0;
        }
        mySum+=root->val;
        if(solve(root->left, mySum, targetSum))
            return true;
        if(solve(root->right, mySum, targetSum))
            return true;
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(!root)
            return false;
        
        if((!root->left and !root->right) and (root->val == targetSum))
            return true;

        return solve(root, 0, targetSum);

    }
};