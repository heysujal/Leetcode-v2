
//Approach-3 (Using BFS with inner while loop)
//T.C : O(n)
//S.C : O(n) for queue
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        
        int bottomLeft;
        que.push(root);
        
        while(!que.empty()) {
            int n = que.size();

            while(n--) {
                TreeNode* node = que.front();
                que.pop();
                
                
                bottomLeft = node->val;
                
                if(node->right) {
                    que.push(node->right);
                }
                if(node->left) {
                    que.push(node->left);
                }
            }
            
        }
        
        return bottomLeft;
    }
};
