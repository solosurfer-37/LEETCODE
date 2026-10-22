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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> aloo(nums.begin(), nums.end());
        int components = 0;
        ListNode* temp = head ;
        while(temp != nullptr ){
            if (aloo.count(temp->val)) {
                if (temp->next == nullptr || !aloo.count(temp->next->val)) {
                    components++;
                }
            }
            temp = temp->next ;

        }
        return components;
    }
};