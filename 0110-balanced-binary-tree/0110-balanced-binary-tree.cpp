class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return checkheight(root) != -1;
    }

    int checkheight(TreeNode* node) {
        if (node == NULL) return 0;

        int LH = checkheight(node->left);
        if (LH == -1) return -1;

        int RH = checkheight(node->right);
        if (RH == -1) return -1;

        if (abs(RH - LH) > 1) return -1;

        return max(LH, RH) + 1;
    }
};
