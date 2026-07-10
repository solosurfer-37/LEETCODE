/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    void fill(TreeNode* root, map<int, int>& aloo) {
        if (root == nullptr) return;
        aloo[root->val]++;
        fill(root->right, aloo);
        fill(root->left , aloo);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        map<int, int> aloo;
        fill(root, aloo);
        int count = 0;
        for (auto it = aloo.begin(); it != aloo.end(); it++) {
            count++; 
            if (count == k) { 
                return it->first; 
            }
        }
        return 0;
    }
};