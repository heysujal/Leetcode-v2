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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        // 0 based indexing
        int width = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while(!q.empty()){
            // we want leftMost idx and rightMost idx 
            // for every level
            int size = q.size();
            vector<long long> v;
            for(int i = 0; i < size; i++){
                auto [node, idx] = q.front();
                q.pop();
                v.push_back(idx);
                if(node->left){
                    q.push({node->left, (long long)2*idx + 1});
                }
                if(node->right){
                    q.push({node->right, (long long)2*idx + 2});
                }
            }
            // level is processed 
            // now, do right - left + 1
            width = max(width, (int)(v.back() - v.front() + 1));
        }
        return width;
    }
};