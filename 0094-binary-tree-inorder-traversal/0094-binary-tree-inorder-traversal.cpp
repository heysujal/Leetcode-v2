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
// Using Morris Traversal
// while curr exists
// at a node whether we have to move left or right is determined whether 
// the node has a left subtree. If it doesn’t we store and  move to the right.
//  If there is a left subtree then we see its rightmost child. 
// If the rightmost child is pointing to NULL we point it to curr and move curr to left,
//  If the rightmost child is already pointing to curr then
// we remove that link and move curr to right.
    void MorrisInorder(TreeNode* root, vector<int> &inorder){
        TreeNode* curr = root;
        while(curr){
            if(!curr->left){
                inorder.push_back(curr->val);
                curr = curr->right;
            }else{
                // left exists
                TreeNode* p = curr->left;
                // go to its rightmost child
                while(p->right and p->right != curr)
                    p = p->right;
                if(!p->right){
                    p->right = curr;
                    curr = curr->left;
                }else{
                    p->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        vector<int> inorder;
        MorrisInorder(root, inorder);
        return inorder;
    }
};