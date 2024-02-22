/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(inorder.size()==0||postorder.size()==0) return NULL;
        
        TreeNode * root=buildSubTree(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
        return root;
    }
    TreeNode *buildSubTree(vector<int> &inorder, vector<int> &postorder, int instart, int inend,int poststart,int postend) {
        
        if(instart>inend||poststart>postend) return NULL;
        if((inend-instart)!=(postend-poststart))
            return NULL;
        
        if((instart==inend)&&(poststart==postend))
        {
            TreeNode *newNode= new TreeNode(inorder[instart]);
            return newNode;
        }
        int root=postorder[postend];
        //find where is the root in inorder array
        int i=0;
        for(i=instart;i<=inend;i++)
        {
            if(inorder[i]==root) break;
        }
        TreeNode *newNode=new TreeNode(root);
        newNode->left=buildSubTree(inorder, postorder,instart,i-1,poststart,poststart+i-1-instart);
        newNode->right=buildSubTree(inorder,postorder,i+1,inend,poststart+i-instart,postend-1);
        return newNode;
    }
};