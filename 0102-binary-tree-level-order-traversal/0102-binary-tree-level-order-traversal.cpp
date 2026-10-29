class Solution {
public:
    void trav(TreeNode* root , int level , vector<vector<int >>& ans  ){
        if(root == nullptr ){
            return ;
        }

        if(ans.size() <= level){
            ans.push_back({});
        }
        ans[level].push_back(root->val);

        trav(root->left , level + 1 , ans );
        trav(root->right , level + 1 , ans );
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int >> ans ;
        trav(root , 0 , ans );
        return ans ;

    }
};