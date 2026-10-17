/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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