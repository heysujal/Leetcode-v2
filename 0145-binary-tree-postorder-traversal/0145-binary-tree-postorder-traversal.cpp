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
    vector<int> MorrisPostorder(TreeNode* root){
        vector<int> postorder;
        TreeNode* curr = root;
        while(curr){
            if(!curr->right){
                postorder.push_back(curr->val);
                curr = curr->left;
            }else{
                // right exists
                TreeNode* p = curr->right;
                // move to leftmost child
                while(p->left and p->left != curr)
                    p = p->left;
                if(!p->left){
                    p->left = curr;
                    postorder.push_back(curr->val);
                    curr = curr->right;
                }else{
                    p->left = NULL;
                    curr = curr->left;
                }
            }
        }
        reverse(postorder.begin(),postorder.end());
        return postorder;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        return MorrisPostorder(root);
    }
};