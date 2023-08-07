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
    void levelOrder(TreeNode* root, vector<vector<TreeNode*>> &ans) {
        if(!root)
            return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){  
            int size = q.size();
            vector<TreeNode*> v;
            for(int i = 0; i < size ; i++){
                auto front = q.front();
                q.pop();
                v.push_back(front);
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            ans.push_back(v);
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* oldTree = root;
            root = new TreeNode(val);
            root->left = oldTree;
            return root;
        }
        vector<vector<TreeNode*>> ans;
        levelOrder(root,ans);
        vector<TreeNode*> &v = ans[depth-2];
        for(auto child : v){
            TreeNode* tempLeft = child->left;
            TreeNode* tempRight = child->right;
            child->left = new TreeNode(val);
            child->right = new TreeNode(val);
            child->left->left = tempLeft;
            child->right->right = tempRight;
        }
        return root;
    }
};