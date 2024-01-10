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
    unordered_map<TreeNode*, TreeNode*> parentMap;
    void findNodeAndFillParent(TreeNode* root, TreeNode* &burnStart, int target, TreeNode* parent){
        if(!root) return;
        parentMap[root] = parent;
        if(root->val == target){
            burnStart = root;
        }
        findNodeAndFillParent(root->left, burnStart, target, root);
        findNodeAndFillParent(root->right, burnStart, target, root);
    }
    int amountOfTime(TreeNode* root, int start) {
        // we need address of start
        int t = -1;
        unordered_map<int, bool> vis;
        TreeNode* burnStart;
        findNodeAndFillParent(root, burnStart, start, nullptr);
        vis[start] = true;
        queue<TreeNode*> q;
        q.push(burnStart);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto f = q.front();
                q.pop();
                if(f->left and !vis[f->left->val]){
                    vis[f->left->val] = true;
                    q.push(f->left);
                }
                if(f->right and !vis[f->right->val]){
                    vis[f->right->val] = true;
                    q.push(f->right);
                }
                if(parentMap[f] and !vis[parentMap[f]->val]){
                    vis[parentMap[f]->val] = true;
                    q.push(parentMap[f]);
                }
            }
            t++;
        }
        return t;
    }
};