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
    int maxPathSum(TreeNode* root) {
        int diameter=INT_MIN;
        height(root,diameter);
        return diameter;
    }
    int height(TreeNode* node ,int &diameter){
           if(node==NULL) return 0;
           int lh=max(0,height(node->left,diameter));
           int rh=max(0,height(node->right,diameter));
           diameter=max(diameter,lh+rh+node->val);
           return node->val+max(lh,rh);
    }
};