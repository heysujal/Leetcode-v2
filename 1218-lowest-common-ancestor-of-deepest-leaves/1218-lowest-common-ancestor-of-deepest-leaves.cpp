class Solution {
public:
// Make using of height to see the deepest left or right subtree
// whoever is deepest will be having a lower level in level order traversal
    int getDepth(TreeNode* root) {
        if (!root)
            return 0;
        return max(getDepth(root->right), getDepth(root->left)) + 1;
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root)
            return NULL;
        
        int right_depth = getDepth(root->right);
        int left_depth = getDepth(root->left);
        
        if (right_depth == left_depth)
            return root;
        if (right_depth > left_depth) 
            return lcaDeepestLeaves(root->right);
        else 
            return lcaDeepestLeaves(root->left);
    }
};