class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            TreeNode* node2 = new TreeNode(val);
            root = node2;
            return root;
            // return new TreeNode(val);
        }
        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        }

        else {
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }
};