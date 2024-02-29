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
    // bfs
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool even = true;
        while(!q.empty()){
            int size = q.size();
            if(even){
                int prev = -1;
                for(int i = 0; i < size; i++){
                    auto node = q.front();
                    q.pop();
                    if(node->val % 2 == 0 or prev >= node->val){ // ye to even nikla
                        return false;
                    }
                    if(node->left){
                        q.push(node->left);
                    }
                    if(node->right){
                        q.push(node->right);
                    }
                    prev = node->val;
                }
            }
            else{
                int prev = 1e9;
                for(int i = 0; i < size; i++){
                    auto node = q.front();
                    q.pop();
                    if(node->val % 2 != 0 or prev <= node->val){ // ye to even nikla
                        return false;
                    }
                    if(node->left){
                        q.push(node->left);
                    }
                    if(node->right){
                        q.push(node->right);
                    }
                    prev = node->val;
                }
            }
            even = !even;
        }
        return true;
    }
};