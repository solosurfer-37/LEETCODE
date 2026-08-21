/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> aloo;
        ListNode* temp = head;
        while (temp != NULL) {
            if (aloo.find(temp) != aloo.end()) {
                return true;
            }
            aloo.insert(temp);
            temp = temp->next;
        }

        return false;
    }
};