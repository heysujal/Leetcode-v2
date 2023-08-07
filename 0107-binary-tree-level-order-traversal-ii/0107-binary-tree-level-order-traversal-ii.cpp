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
    int height(TreeNode* root){
        return root ? 1 + max(height(root->left),height(root->right)) : 0;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
            return {};
        int n = height(root);
        vector<vector<int>> ans(n);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> v;
            for(int i = 0; i < size; i++){
                TreeNode* front  = q.front();
                q.pop();
                v.push_back(front->val);
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            ans[n-1] = v;
            n--;
        }
        return ans;
    }
};