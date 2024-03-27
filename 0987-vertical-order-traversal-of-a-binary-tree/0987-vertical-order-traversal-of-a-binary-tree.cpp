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
typedef TreeNode Node;
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root)
            return {};

        map<int, map<int, vector<int>>> nodes;
        queue<pair<Node*, pair<int, int>>> q;
        vector<vector<int>> ans;
        q.push(make_pair(root, make_pair(0,0)));

        while(!q.empty()){
            pair<Node*, pair<int, int>> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second.first;
            int level = temp.second.second;
            nodes[hd][level].push_back(frontNode->val);
            if(frontNode->left)
                q.push(make_pair(frontNode->left, make_pair(hd-1, level+1)));
            if(frontNode->right)
                q.push(make_pair(frontNode->right, make_pair(hd+1, level+1)));
        }

        for(auto i:nodes){
            vector<int> t;
            for(auto j : i.second){
                    for(int k  : j.second)
                        t.push_back(k);
            }
            sort(t.begin(), t.end());
            ans.push_back(t);
        }
        return ans;
    }
};