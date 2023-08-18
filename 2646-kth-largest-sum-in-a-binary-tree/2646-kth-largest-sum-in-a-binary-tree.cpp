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
    void levelOrderBFS(TreeNode* root, vector<long long> &ans){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){  
            int size = q.size();
            long long sum = 0;
            for(int i = 0; i < size; i++){
                auto front = q.front();
                q.pop();
                sum += front->val;
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            ans.push_back(sum);
        }
    }    
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> ans;
        levelOrderBFS(root,ans);
        sort(ans.begin(),ans.end());
        int n = ans.size();
        if(n < k) return -1;
        return ans[n-k];
    }
};