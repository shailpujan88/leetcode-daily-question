class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inmpp;
        for (int i = 0; i < inorder.size(); i++) {
            inmpp[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0,
                               inorder.size() - 1, inmpp);
    }

private:
    TreeNode* buildTreeHelper(vector<int>& preorder, int prestart, int preend,
                              vector<int>& inorder, int instart, int inend,
                              map<int, int>& inmpp) {
        if (prestart > preend || instart > inend)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[prestart]);
        int inroot = inmpp[root->val];
        int numleft = inroot - instart;

        root->left = buildTreeHelper(preorder, prestart + 1, prestart + numleft,
                                     inorder, instart, inroot - 1, inmpp);

        root->right = buildTreeHelper(preorder, prestart + numleft + 1, preend,
                                      inorder, inroot + 1, inend, inmpp);

        return root;
    }
};
