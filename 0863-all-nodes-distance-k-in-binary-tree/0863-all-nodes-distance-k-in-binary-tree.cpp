/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void markParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent_track, TreeNode* target){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
             TreeNode* current=q.front();
             q.pop();
             if(current->left){
                parent_track[current->left]=current;
                q.push(current->left);
             }
              if(current->right){
                parent_track[current->right]=current;
                q.push(current->right);
             }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
      unordered_map< TreeNode*,TreeNode*>parent_track;
      markParent(root,parent_track,target); 
      unordered_map<TreeNode*,bool>vis;
      queue<TreeNode*>q;
      q.push(target);
      vis[target]=true;
      int current=0;
      while(!q.empty()){
        int n=q.size();
        if(current++==k) break;
        for(int i=0;i<n;i++){
          TreeNode* current=q.front();
             q.pop();
             if(current->left && !vis[current->left]){
                q.push(current->left);
                vis[current->left]=true;
             }
              if(current->right && !vis[current->right]){
                q.push(current->right);
                vis[current->right]=true;
             } 
              if(parent_track[current]&& !vis[parent_track[current]]){
                q.push(parent_track[current]);
                vis[parent_track[current]]=true;
             }
        }


      }
      vector<int> ans;
      while(!q.empty()){
        TreeNode* current=q.front();
             q.pop(); 
             ans.push_back(current->val);
      }
      return ans;
    }
};