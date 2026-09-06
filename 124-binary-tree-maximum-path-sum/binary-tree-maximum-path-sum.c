int dfs(struct TreeNode* node, int* max_sum) {
    if (node == NULL) {
        return 0;
    }
    int l_val = dfs(node->left, max_sum);
    int r_val = dfs(node->right, max_sum);
    int left = l_val > 0 ? l_val : 0;
    int right = r_val > 0 ? r_val : 0;

    int current_split = node->val + left + right;

    if (current_split > *max_sum) {
        *max_sum = current_split;
    }

    return node->val + (left > right ? left : right);
}

int maxPathSum(struct TreeNode* root) {
    int max_sum = -2147483648; 
    dfs(root, &max_sum);
    return max_sum;
}