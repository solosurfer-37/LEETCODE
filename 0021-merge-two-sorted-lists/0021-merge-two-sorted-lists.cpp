class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> arr;
        ListNode* temp = list1;
        while (temp != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        temp = list2;
        while (temp != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        sort(arr.begin(), arr.end());
        
        if (arr.empty()) {
            return nullptr;
        }
        ListNode* head = new ListNode(arr[0]);
        ListNode* current = head;
        
        for (size_t i = 1; i < arr.size(); i++) {
            current->next = new ListNode(arr[i]);
            current = current->next;
        }
        
        return head;
    }
};