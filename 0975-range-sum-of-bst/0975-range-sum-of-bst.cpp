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
    int sum = 0;

    void MorrisInorder(TreeNode*root, int low, int high){
        TreeNode* curr = root;
        while(curr){
            if(!curr->left){
                if(curr->val >= low and curr->val <= high)
                    sum += curr->val;
                curr = curr->right;
            }
            else{
                // left exists
                TreeNode* p = curr->left;
                // go to its rightmost child
                while(p->right and p->right != curr){
                    p = p->right;
                }
                // 2 possibilities : either p->right = null or it is curr     
                if(!p->right){
                    p->right = curr;
                    curr = curr->left;
                }
                else{
                    //p->right is curr
                    p->right = nullptr;
                    if(curr->val >= low and curr->val <= high)
                        sum += curr->val;
                    curr = curr->right;
                }
            }
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)
            return 0;
        MorrisInorder(root, low, high);
        return sum;
    }       
};