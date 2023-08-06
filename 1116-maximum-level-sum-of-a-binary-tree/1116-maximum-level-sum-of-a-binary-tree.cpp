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
    vector<int> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*> q;
        vector<int> ans(2);
        ans[0] = -1e9;
        q.push(root);
        int level = 0;
        while(!q.empty()){  
            int size = q.size();
            // vector<int> v;
            int sum = 0;
            level++;
            for(int i = 0; i < size ; i++){
                auto front = q.front();
                q.pop();
                // v.push_back(front->val);
                sum += front->val;
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            if(ans[0] < sum){
                ans[0] = sum;
                ans[1] = level;
            }
        }
        return ans;
    }
    int maxLevelSum(TreeNode* root) {
        return levelOrder(root)[1];
    }
};