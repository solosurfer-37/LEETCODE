class Solution {
public:
    TreeNode* create(int i, vector<int>& aloo) {
        if (i < aloo.size()) {
            TreeNode* newNode = new TreeNode(aloo[i]);
            newNode->left = nullptr;
            newNode->right = create(i + 1, aloo);
            return newNode;
        }
        return nullptr;
    }
    void pushing(TreeNode* root, vector<int>& aloo) {
        if (root == nullptr) {
            return;
        }
        pushing(root->left, aloo);
        aloo.push_back(root->val);
        pushing(root->right, aloo);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> aloo;
        pushing(root, aloo);
        sort(aloo.begin(), aloo.end());
        return create(0, aloo);
    }
};