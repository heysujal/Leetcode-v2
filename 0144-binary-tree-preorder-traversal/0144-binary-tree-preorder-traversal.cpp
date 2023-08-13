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
    vector<int> MorrisPreorder(TreeNode* root){
        vector<int> preorder;
        TreeNode* curr = root;
        while(curr){
            if(!curr->left){
                preorder.push_back(curr->val);
                curr = curr->right;
            }else{
                // left exists
                TreeNode* p = curr->left;
                // move to rightmost child
                while(p->right and p->right != curr)
                    p = p->right;
                if(!p->right){
                    p->right = curr;
                    preorder.push_back(curr->val);
                    curr = curr->left;
                }else{
                    p->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return preorder;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        return MorrisPreorder(root);
    }
};