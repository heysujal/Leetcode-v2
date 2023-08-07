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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        bool left_to_right = true;
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
            if(!left_to_right)
                reverse(v.begin(),v.end());
            ans.push_back(v);
            left_to_right = !left_to_right;
        }
        return ans;
        
    }
};