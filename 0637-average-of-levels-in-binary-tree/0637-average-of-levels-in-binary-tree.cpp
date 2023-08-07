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
    void levelOrderBFS(TreeNode* root, vector<vector<int>> &ans){
        if(!root)
            return;
        queue<TreeNode*> q;
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
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>> levelOrder;
        vector<double> ans; 
        levelOrderBFS(root,levelOrder);
        for(auto level : levelOrder){
            double sum = 0;
            for(auto x : level)
                sum+=x;
            double val = sum/level.size();
            ans.push_back(val);
        }
        return ans;
    }
};