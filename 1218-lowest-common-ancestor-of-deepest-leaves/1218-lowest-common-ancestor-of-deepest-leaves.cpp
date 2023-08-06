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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        while(!q.empty()){  
            int size = q.size();
            vector<int> v;
            for(int i = 0; i < size ; i++){
                auto front = q.front();
                q.pop();
                v.push_back(front->val);
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
        if(!root)
            return NULL;
        if(root->val == p or root->val == q)
            return root;
        
        TreeNode* leftLCA = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right,p,q);

        if(leftLCA and rightLCA)
            return root;
        if(leftLCA)
            return leftLCA;
        if(rightLCA)
            return rightLCA;
        return NULL;      
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        ans = levelOrder(root);
        vector<int> candi = ans.back();
        return lowestCommonAncestor(root,candi[0],candi.back());
    }
};