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
    TreeNode* helper(int preStart, int preEnd, vector<int> &pre, int inStart, int inEnd, vector<int> &in, unordered_map<int, int> &mp){
        if(preStart > preEnd or inStart > inEnd){
            return nullptr;
        }
        TreeNode* root = new TreeNode(pre[preStart]);
        int idx = mp[pre[preStart]]; // find posi in inorder
        int len = (idx-1) - inStart + 1;
        root->left = helper(preStart + 1, preStart + len, pre, inStart, idx-1, in, mp);
        root->right = helper(preStart + len + 1, preEnd, pre, idx+1, inEnd, in, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return helper(0, pre.size() - 1, preorder, 0, in.size() - 1, inorder, mp);
    }
};