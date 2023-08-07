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
    // Using LevelOrder
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        queue<pair<TreeNode*,int>> q; // node,level
        vector<int> ans;
        q.push({root,0});
        while(!q.empty()){  
            int size = q.size();
            for(int i = 0; i < size ; i++){
                auto front = q.front();
                TreeNode* node = front.first;
                int level = front.second;
                q.pop();
                if(ans.size() == level)
                    ans.push_back(node->val);
                if(node->right)
                    q.push({node->right,level+1});
                if(node->left)
                    q.push({node->left,level+1});
            }
        }
        return ans;
    }
};