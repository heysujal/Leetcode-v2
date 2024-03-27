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
    void pre(TreeNode* root, string path, vector<string> &allPaths){
        if(!root){
            return;
        }
        if(!root->left and !root->right){
            string num = to_string(root->val);
            path += num;
            allPaths.push_back(path);
            return;
        }

        string num = to_string(root->val);
        path += num;
        path += "->";
        pre(root->left, path, allPaths);
        pre(root->right, path, allPaths);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        vector<string> allPaths;
        string path = "";
        pre(root, path, allPaths);
        return allPaths;
    }
};