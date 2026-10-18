class Solution {
public:
    void iterate(TreeNode* temp , vector<int >& ans ){
        if(temp == nullptr ){
            return ;
        }
        ans.push_back(temp->val) ; 
        iterate(temp->left , ans ) ;
        iterate(temp->right , ans ) ;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        TreeNode* temp = root1;
        iterate(temp , ans ) ;
        temp = root2;
        iterate(temp , ans ) ;
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};