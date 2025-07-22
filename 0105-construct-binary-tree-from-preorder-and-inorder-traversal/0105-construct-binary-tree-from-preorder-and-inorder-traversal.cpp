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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      map<int ,int>inmpp;
       for(int i=0;i<inorder.size();i++){
        inmpp[inorder[i]]=i;
       }
               TreeNode*root= buildTree2(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inmpp);
               return  root;
       } 
        TreeNode* buildTree2(vector<int>& preorder,int prestart,int preend,vector<int>& inorder,int instart,int inend,map<int ,int>inmpp){
            if(prestart>preend || instart>inend) return NULL;
            TreeNode* root=new TreeNode(preorder[prestart]);
            int inroot=inmpp[root->val];
            int numleft=inroot-instart;
            root->left=buildTree2(preorder,prestart+1, prestart+numleft,inorder,instart,inroot-1,inmpp);
             root->right=buildTree2(preorder,prestart+numleft+1, preend,inorder,inroot+1,inend,inmpp);
        return root;
    }
};