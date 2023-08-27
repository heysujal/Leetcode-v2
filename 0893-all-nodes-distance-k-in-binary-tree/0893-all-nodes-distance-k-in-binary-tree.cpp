/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    unordered_map<TreeNode*,TreeNode*> mp;
    unordered_map<TreeNode*,bool> vis;
    void fillMap(TreeNode* root, TreeNode* parent){
        if(!root) return;
        mp[root] = parent;
        fillMap(root->left, root);
        fillMap(root->right, root);
    }
    void bfs(TreeNode* root, TreeNode* target, int k){
        if(!root) return;
        queue<pair<TreeNode*,int>> q;
        q.push({target,k});
        while(!q.empty()){
            auto node = q.front().first;
            int K = q.front().second;
            q.pop();
            if(K==0){ ans.push_back(node->val);}
            if(node->left and !vis[node->left]) q.push({node->left,K-1});
            if(node->right and !vis[node->right]) q.push({node->right,K-1});
            if(mp[node] and !vis[mp[node]]) q.push({mp[node],K-1});
            vis[node] = true;
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        fillMap(root, nullptr);
        bfs(target, target, k);
        return ans;
    }
};