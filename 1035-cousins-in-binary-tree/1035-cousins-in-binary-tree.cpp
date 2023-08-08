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
    pair<int,TreeNode*> X; // level, parnet
    pair<int,TreeNode*> Y; // level , parent
    void levelOrderBFS(TreeNode* root, int x, int y){
        if(!root)
            return;
        queue<pair<TreeNode*,TreeNode*>> q; // node,parent
        q.push({root,NULL});
        int level = 0;
        while(!q.empty()){  
            int size = q.size();
            for(int i = 0; i < size ; i++){
                auto root = q.front().first;
                auto parent = q.front().second;
                q.pop();
                if(root->val == x)
                    X = {level,parent};
                if(root->val == y)
                    Y = {level,parent};
                if(root->left)
                    q.push({root->left,root});
                if(root->right)
                    q.push({root->right,root});
            }
            level++;
        }
    }
    bool isCousins(TreeNode* root, int x, int y) {
        levelOrderBFS(root,x,y);
        return X.first == Y.first and X.second != Y.second;
    }
};