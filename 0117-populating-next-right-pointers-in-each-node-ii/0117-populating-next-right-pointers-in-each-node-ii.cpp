/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
void levelOrderDFS(Node* root, int level, vector<vector<Node*>> &ans) {
        if(!root)
            return;
        if(ans.size() == level)
            ans.push_back({}); //creates a empty array for curlvl (ans[level] = {})
        ans[level].push_back(root);
        levelOrderDFS(root->left,level+1,ans);
        levelOrderDFS(root->right,level+1,ans);
    }
    Node* connect(Node* root) {
        vector<vector<Node*>> lvl;
        levelOrderDFS(root,0,lvl);
        for(auto &v : lvl){
            int n = v.size();
            for(int i = 0; i < n-1; i++){
                v[i]->next = v[i+1];
            }
        }
        return root;
    }
};