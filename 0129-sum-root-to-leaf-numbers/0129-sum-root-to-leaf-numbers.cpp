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
    int sumNumbers(TreeNode* root) {
        queue<pair<TreeNode*,int>> q; // <node,prevSum>
        q.push({root,0});
        int finSum = 0;
        while(!q.empty()){
            auto root = q.front().first;
            auto prevSum = q.front().second;
            q.pop();
            if(!root->left and !root->right)
                finSum += prevSum*10 + root->val;
            if(root->left)
                q.push({root->left, prevSum*10 + root->val});
            if(root->right)
                q.push({root->right, prevSum*10 + root->val});
        }
        return finSum;
    }
};