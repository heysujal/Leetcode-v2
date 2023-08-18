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
    unordered_map<TreeNode*, TreeNode*> parent;  // son=>parent  
    unordered_set<TreeNode*> visit;    //record visied node  
    void findParent(TreeNode* node){
        if(!node ) return;
        if( node->left ){
            parent[node->left] = node;
            findParent(node->left);
        }
        if( node->right){
            parent[node->right] = node;
            findParent(node->right);
        }
    }
    void dfs(TreeNode* node, int K) {
        if (!node) return;
        if (visit.count(node) > 0) return;
        visit.insert(node);
        if (K == 0) {
            ans.push_back(node->val);
            return;
        }
        dfs(node->left, K - 1);
        dfs(node->right, K - 1);
        dfs(parent[node], K - 1);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if( !root ) return {};
        findParent(root);
        dfs(target,k);
        return ans;
    }
};