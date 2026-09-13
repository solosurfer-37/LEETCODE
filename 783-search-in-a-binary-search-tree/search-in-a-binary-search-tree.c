struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL) {
        return NULL;
    }
    while (root != NULL) {
        if (root->val == val) {
            return root;
        } else if (root->val > val) {
            root = searchBST(root->left, val);
        } else {
            root = searchBST(root->right, val);
        }
    }
    return NULL;
}