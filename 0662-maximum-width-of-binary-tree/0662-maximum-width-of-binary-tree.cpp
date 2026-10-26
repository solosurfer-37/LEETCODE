class Solution {
public:
    long long ans = 0;
    vector<long long> v; 

    void dfs(TreeNode* root, int lvl, long long idx) {
        if (root == nullptr) return;

        if (lvl == v.size()) {
            v.push_back(idx);
        }

        ans = max(ans, idx - v[lvl] + 1);
        dfs(root->left, lvl + 1, 2 * (idx - v[lvl]));
        dfs(root->right, lvl + 1, 2 * (idx - v[lvl]) + 1);
    }

    int widthOfBinaryTree(TreeNode* root) {
        ans = 0;
        v.clear();
        dfs(root, 0, 0);
        return ans;
    }
};