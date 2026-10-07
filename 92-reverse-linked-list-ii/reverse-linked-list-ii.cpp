class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right ) return head ;
        vector<int> ans ;
        struct ListNode* curr = head ;
        int count = 1 ;
        while(curr != nullptr ){
            if( count >= left  && count <= right ){
                ans.push_back(curr->val) ;
            }
            count++ ;
            curr = curr->next ;
        }
        curr = head ; 
        count = 1 ;
        int size = ans.size() -1;
        while(curr != nullptr ){
            if( count >= left  && count <= right ){
                curr->val = ans[size] ;
                size--;
            }
            count++ ;
            curr = curr->next ;
        }
        return head ;
    }
};