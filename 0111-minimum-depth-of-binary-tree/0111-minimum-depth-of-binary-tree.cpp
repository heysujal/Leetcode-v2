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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode* >q; 
        q.push(root);
        int level = 0;
        while(q.size() != 0){
            int size = q.size();
            level++;
            for(int i=0;i<size;i++){
                TreeNode* currNode = q.front();
                q.pop();
                if(currNode->left == NULL && currNode->right == NULL) return level; // this is our answer
                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
            }
        }
        return -1;
    }
};