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
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head ) return nullptr ;
        vector<int> ans ;
        struct ListNode* curr = head ;
        while(curr != nullptr ){
            ans.push_back(curr->val);
            curr = curr->next ;
        }

        for(int i = 0; i < ans.size() ; i++ ){
            int key = ans[i];
            int j = i-1 ;

            while(j>= 0 && ans[j] > key ){
                ans[j+1 ] = ans[j];
                j-- ;
            }  

            ans[j+1]= key ;
        }
        curr = head ;
        for(int i = 0 ; i < ans.size() ; i++ ){
            curr->val = ans[i] ;
            curr = curr->next ;
        }

        return head ;
    }
};