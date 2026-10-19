class Solution {
public:
   void order(TreeNode* root ,int level , vector<vector<int>>& ans  ){
    if(root == nullptr ){
        return ;
    }

    if(ans.size() <= level ){
        ans.push_back({});
    }
    ans[level].push_back(root->val ) ;
    order(root->left , level+1 , ans ) ;
    order(root->right, level +1 , ans ) ;
   }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr){
            return {} ;
        }
        vector<vector<int>> ans ;
        order(root ,0 , ans ) ;
        return ans ;
    }
};