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
        TreeNode* solve(int preStart, int preEnd, vector<int> &preOrder, int inStart, int inEnd, vector<int> &inOrder, unordered_map<int,int> &mp){
        // base case(difficult)
        if(preStart > preEnd or inStart > inEnd)
            return nullptr;
        TreeNode* root = new TreeNode(preOrder[preStart]);
        int idx = mp[preOrder[preStart]];
        int len = idx-1 - inStart+1;
        root->left = solve(preStart+1,preStart+len,preOrder,inStart,idx-1,inOrder,mp);
        root->right = solve(preStart+len+1,preEnd,preOrder,idx+1,inEnd,inOrder,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int,int> mp;
        int i = 0;
        for(auto x : inorder)
            mp[x] = i++;
        return solve(0,n-1,preorder,0,n-1,inorder,mp);
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(),inorder.end());
        return buildTree(preorder,inorder);
    }
};