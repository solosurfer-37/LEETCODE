
class Solution {
public:
    TreeNode* build(vector<int>& ans , int low , int high ){
        if(low > high ) return nullptr ;

        int mid = low + (high-low)/2;

        TreeNode* root = new TreeNode(ans[mid]) ;
        root->left = build(ans , low , mid-1 );
        root->right = build(ans , mid+1 , high ) ;

        return root ;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int > ans ;
        ListNode* temp = head ;
        while(temp != NULL ){
            ans.push_back(temp->val);
            temp = temp->next ;
        }

        return build(ans , 0 , ans.size() - 1 );
    }
};