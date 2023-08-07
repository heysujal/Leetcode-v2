/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)
            return {};
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){  
            int size = q.size();
            vector<int> v;
            for(int i = 0; i < size; i++){
                auto front = q.front();
                q.pop();
                v.push_back(front->val);
                // if(front->left)
                //     q.push(front->left);
                // if(front->right)
                //     q.push(front->right);
                for(auto child : front->children)
                    if(child)
                        q.push(child);
            }
            ans.push_back(v);
        }
        return ans;
    }
};