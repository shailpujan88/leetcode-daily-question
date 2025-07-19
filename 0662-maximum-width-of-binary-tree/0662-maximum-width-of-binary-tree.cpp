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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int maxwidth=0;
        queue<pair<TreeNode*,int>>q;//impkemt the queue for storing the node and the indexing so doing by using pair 
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            int min_for_overflow=q.front().second;
            int first,last;
            for(int i=0;i<n;i++){
                int cur_id=q.front().second-min_for_overflow;
                  TreeNode* node=q.front().first;
                  q.pop();
                  if(i==0) first=cur_id;
                  if(i==n-1) last=cur_id;
                  if(node->left) q.push({node->left,cur_id*2+1});
                  if(node->right) q.push({node->right,cur_id*2+2});

            }
            maxwidth=max(maxwidth,last-first+1);

        }
        return maxwidth;

    }
};