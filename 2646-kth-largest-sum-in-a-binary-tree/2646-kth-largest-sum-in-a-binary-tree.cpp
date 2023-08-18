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
    long long levelOrderBFS(TreeNode* root, int k){
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){  
            int size = q.size();
            long long sum = 0;
            for(int i = 0; i < size; i++){
                auto front = q.front();
                q.pop();
                sum += front->val;
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            pq.push(sum);
            if(pq.size() > k)
                pq.pop();
        }
        if(pq.size() < k)
            return -1;
        return pq.top();
    }    
    long long kthLargestLevelSum(TreeNode* root, int k) {
        return levelOrderBFS(root,k);
    }
};