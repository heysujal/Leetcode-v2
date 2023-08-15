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
    TreeNode* LCA(TreeNode *root, int p, int q){
        if(!root) return nullptr;
        if(root->val == p or root->val == q) return root;
        TreeNode* left = LCA(root->left, p, q);
        TreeNode* right = LCA(root->right, p, q);
        if(left and right) return root;
        return left ? left : right;
    }
    // lca to node
    bool lcaToNode(TreeNode* root, int target, string &path){
        if(!root) return false; // nothing to search in so it target doesn't exist
        if(root->val == target) return true;
        path += 'L';
        if(lcaToNode(root->left, target, path))
            return true;
        path.pop_back();
        path += 'R';
        if(lcaToNode(root->right, target, path))
            return true; 
        path.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // get lca of startValue and destination
        TreeNode* lca = LCA(root, startValue, destValue);
        string lcaToStart = "";
        string lcaToDest = "";
        lcaToNode(lca, startValue, lcaToStart);
        lcaToNode(lca, destValue, lcaToDest);
        for(auto &x : lcaToStart)
            x = 'U';
        return lcaToStart + lcaToDest;
    }
};