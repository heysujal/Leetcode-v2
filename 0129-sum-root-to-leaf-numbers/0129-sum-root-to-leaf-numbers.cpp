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
        stack<pair<TreeNode*,int>> s; // <node,prevSum>
        s.push({root,0});
        int finSum = 0;
        while(!s.empty()){
            auto root = s.top().first;
            auto prevSum = s.top().second;
            s.pop();
            if(!root->left and !root->right)
                finSum += prevSum*10 + root->val;
            if(root->right)
                s.push({root->right, prevSum*10 + root->val});
            if(root->left)
                s.push({root->left, prevSum*10 + root->val});
        }
        return finSum;
    }
};