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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> result = {-1, -1};
        
        if (!head || !head->next || !head->next->next) {
            return result;
        }
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        int first_critical = -1;
        int last_critical = -1;
        int min_dist = INT_MAX;
        int index = 1;
        
        while (curr->next != nullptr) {
            ListNode* next_node = curr->next;
            
            if ((curr->val > prev->val && curr->val > next_node->val) ||
                (curr->val < prev->val && curr->val < next_node->val)) {
                
                if (first_critical == -1) {
                    first_critical = index;
                } else {
                    min_dist = min(min_dist, index - last_critical);
                }
                last_critical = index;
            }
            
            prev = curr;
            curr = next_node;
            index++;
        }
        
        if (min_dist != INT_MAX) {
            result[0] = min_dist;
            result[1] = last_critical - first_critical;
        }
        return result;
    }
};