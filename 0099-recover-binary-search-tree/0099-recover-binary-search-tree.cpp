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

    // There can be 2 cases 
    // => violation are adjacent in inorder (make use of first and middle)
    // => violation are not adjacent (make use of first and last)

    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;
    
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(prev and root->val < prev->val){
            //  first time ?
            if(first == nullptr){
                first = prev;
                middle = root;
            }
            // if this is second violation then mark it as last node
            else{
                last = root;
            }
        }
        // mark this node as previous
        prev = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN);
        inorder(root);    
        if(first and last) swap(first->val, last->val);
        else if(first and middle) swap(first->val, middle->val);
    }
};