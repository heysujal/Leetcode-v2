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
    unordered_map<int, int> mp;
    bool isPathPalindrome(){
        int odd_count = 0;
        for(auto f : mp){
            if(f.second % 2 != 0){
                odd_count++;
                if(odd_count > 1){
                    return false;
                }
            }
        }
        return true;
    }
    int helper(TreeNode* root){
        if(!root){
            return 0;
        } 
        if(!root->left and !root->right){
            mp[root->val]++;
            int t = isPathPalindrome();
            mp[root->val]--;
            return t;
        }
        int ans = 0;
        mp[root->val]++;
        ans += helper(root->left);
        ans += helper(root->right);
        mp[root->val]--;
        return ans;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        mp.clear();
        return helper(root);
    }
};