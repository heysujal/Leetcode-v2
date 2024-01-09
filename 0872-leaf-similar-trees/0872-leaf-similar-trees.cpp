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
    void MorrisTraversal(TreeNode* root, vector<int> &v){
        TreeNode* curr = root;
        while(curr){
            if(!curr->left){
                if(!curr->left and !curr->right)
                    v.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* p = curr->left;
                while(p->right and p->right != curr){
                    p = p->right;
                }
                // 2 possibilities
                if(!p->right){
                    p->right = curr;
                    curr = curr->left;
                }
                else{
                    p->right = nullptr;
                    if(!p->left and !p->right)
                        v.push_back(p->val);
                    curr = curr->right;
                }
            }
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        MorrisTraversal(root1, v1);
        MorrisTraversal(root2, v2);
        for(auto x : v1)
            cout << x << " ";
        cout<<endl;
        for(auto y : v2)
            cout << y << " ";
        return v1 == v2;
    }
};