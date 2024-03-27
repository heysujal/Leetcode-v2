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
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()){
            // we want leftMost idx and rightMost idx 
            // for every level
            int leftMost;
            int rightMost;
            // this is the leftMost node of every level
            // we use it as a reference/origin to find distance
            int origin = q.front().second;
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto node = q.front().first;
                auto idx = q.front().second - origin;
                q.pop();
                if(i == 0){
                    leftMost = idx;
                }
                if(i == size - 1){
                    rightMost = idx;
                }
                if(node->left){
                    q.push({node->left, 2*idx + 1});
                }
                if(node->right){
                    q.push({node->right, 2*idx + 2});
                }
            }
            // level is processed 
            // now, do right - left + 1
            width = max(width, rightMost - leftMost + 1);
        }
        return width;
    }
};