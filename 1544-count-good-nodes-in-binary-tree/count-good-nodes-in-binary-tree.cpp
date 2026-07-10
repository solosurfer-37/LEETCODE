/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int Max(TreeNode* root , int value ){
        if(root == nullptr) return 0;
        int count = 0;
        if(root->val >= value ) {
            count = 1;
            value = root->val;
        }
        
        count += Max(root->left , value);
        count += Max(root->right , value);
        
        return count;
    }
    
    int goodNodes(TreeNode* root) {
        if(root == nullptr) { return 0; }
        return Max(root , root->val);
    }
};