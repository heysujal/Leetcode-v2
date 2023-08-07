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
    void levelOrder(TreeNode* root,vector<vector<int>> &ans) {
        if(!root)
            return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){  
            int size = q.size();
            vector<int> v;
            for(int i = 0; i < size ; i++){
                auto front = q.front();
                q.pop();
                v.push_back(front->val);
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            ans.push_back(v);
        }
    }
    bool isSorted(vector<int> &v, bool isEven){
        int n = v.size();
        if(n==1){
            if(isEven)
                return v[0]%2 != 0;
            else
                return v[0]%2 == 0;
        }
        if(isEven){
            // should be in increasing order
            for(int i = 1 ; i < n ; i++){
                bool bothOdd = v[i]%2!=0 and v[i-1]%2!=0;
                if(!bothOdd or v[i-1] >= v[i])
                    return false;
            }
            return true;
        }else{
            // should be in decreasing order
            for(int i = 1 ; i < n ; i++){
                bool bothEven = v[i]%2==0 and v[i-1]%2==0;
                if(!bothEven or v[i-1] <= v[i])
                    return false;
            }
            return true;
        }
    }
    bool isEvenOddTree(TreeNode* root) {
        vector<vector<int>> level_order;
        levelOrder(root,level_order);
        bool isEven = true;
        for(auto &row : level_order){
            bool res = isSorted(row,isEven); // is the order correct
            if(!res)
                return false;
            isEven = !isEven;
        }
        return true;
    }
};