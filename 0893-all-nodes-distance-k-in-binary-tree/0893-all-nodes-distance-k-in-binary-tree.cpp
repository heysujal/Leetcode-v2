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
    bool flag = true;
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
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto node = q.front().first;
                int K = q.front().second;
                q.pop();
                if(!vis[node]){
                    vis[node] = true;
                    if(K==0){ ans.push_back(node->val);}
                    if(node->left) q.push({node->left,K-1});
                    if(node->right) q.push({node->right,K-1});
                    if(mp[node]) q.push({mp[node],K-1});
                }
                
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        fillMap(root, nullptr);
        bfs(target, target, k);
        return ans;
    }
};