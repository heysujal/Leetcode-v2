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
    int levelOrderBFS(TreeNode* root){
        if(!root)
            return 0;
        int maxWidth = 0;
        queue<pair<TreeNode*,int>> q; // node, position
        q.push({root,0});
        while(!q.empty()){  
            int size = q.size();
            vector<long long> v; // to store positions of nodes of a level
            for(int i = 0; i < size ; i++){
                auto front = q.front();
                q.pop();
                TreeNode* node = front.first;
                int idx = front.second;
                v.push_back(idx); // current position
                if(node->left)
                    q.push({node->left,(long long)2*idx});
                if(node->right)
                    q.push({node->right,(long long)2*idx+1});
            }
            maxWidth = max(maxWidth,(int)(v.back()-v.front()+1));
        }
        return maxWidth;
    }
    int widthOfBinaryTree(TreeNode* root) {
        return levelOrderBFS(root);
    }
};