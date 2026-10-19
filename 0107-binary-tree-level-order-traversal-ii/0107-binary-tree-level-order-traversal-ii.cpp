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
    void order(TreeNode* root , int level , vector<vector<int>>& ans ){
        if(root == nullptr ){
            return ;
        }

        if(ans.size() <= level){
            ans.push_back({});
        }

        ans[level].push_back(root->val) ;
        order(root->left , level + 1 , ans );
        order(root->right , level + 1 , ans );

    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == nullptr ){
            return {} ;
        }
        vector<vector<int>> ans ;
        order(root , 0 , ans ) ;
        for(int i = 0 ; i < ans.size()/2 ; i++ ){
            vector<int> temp = ans[i] ;
            ans[i] = ans[ans.size()-i-1];
            ans[ans.size()-i -1 ] = temp ; 
        }
        return ans ;

    }
};