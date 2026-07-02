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
    private:
    int diameter = 0 ;
    int height(TreeNode* root){
            if(root == nullptr ){
                return 0 ;
            }
            int LEFT = 0 , RIGHT = 0 ;
            LEFT = height(root->left);
            RIGHT = height(root->right) ;
            diameter = max(diameter, LEFT + RIGHT ) ;
            return max(LEFT , RIGHT ) + 1 ;
        }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0; 
        height(root);
        return diameter;
    }
};