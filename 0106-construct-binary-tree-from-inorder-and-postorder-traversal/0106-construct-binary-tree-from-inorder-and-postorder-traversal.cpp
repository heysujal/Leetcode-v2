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
    TreeNode* solve(int postStart, int postEnd, vector<int> &postOrder, int inStart, int inEnd, vector<int> &inOrder, unordered_map<int,int> &mp){
        // base case(difficult)
        if(postStart > postEnd or inStart > inEnd)
            return nullptr;
        TreeNode* root = new TreeNode(postOrder[postEnd]);
        int idx = mp[postOrder[postEnd]];
        int len = inEnd-(idx+1)+1;
        root->right = solve(postEnd-len,postEnd-1,postOrder,idx+1,inEnd,inOrder,mp);
        root->left = solve(postStart,postEnd-len-1,postOrder,inStart,idx-1,inOrder,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int,int> mp;
        int i = 0;
        for(auto x : inorder)
            mp[x] = i++;
        return solve(0,n-1,postorder,0,n-1,inorder,mp);
    }
};