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
    int maxDepth(TreeNode* root) {
       
        
        if(!root){
            return 0;
        }
       int maxDepthLeftsearch = maxDepth(root->left);
       int maxDepthRightsearch = maxDepth(root->right);
      return max(maxDepthLeftsearch, maxDepthRightsearch) + 1;
    }
};