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
    void helper(TreeNode* root, vector<int> &pre, vector<int> &in, vector<int> &post){
        if(!root) return;
        pre.push_back(root->val);
        helper(root->left, pre, in, post);
        in.push_back(root->val);
        helper(root->right, pre, in, post);
        post.push_back(root->val);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> pre, in, post;
        helper(root, pre, in, post);
        for(auto x : pre){
            cout<<x << " ";
        }
        cout<<endl;
        for(auto x : in){
            cout<<x << " ";
        }
        cout<<endl;
        for(auto x : post){
            cout<<x << " ";
        }
        cout<<endl;
        return in;
    }
};