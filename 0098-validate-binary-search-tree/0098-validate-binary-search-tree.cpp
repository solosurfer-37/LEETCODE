class Solution {
public:
    bool check(TreeNode* node, long low, long high) {
        if (node == nullptr) return true; 
        if (node->val <= low || node->val >= high) {
            return false;
        }
        return check(node->left, low, node->val) &&  check(node->right, node->val, high);
    }

    bool isValidBST(TreeNode* root) {
        return check(root, LONG_MIN, LONG_MAX);
    }
};