class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        vector<int> small;
        vector<int> big;

        ListNode* temp = head;

        while (temp != nullptr) {
            if (temp->val < x) {
                small.push_back(temp->val);
            } else {
                big.push_back(temp->val);
            }

            temp = temp->next;
        }

        vector<int> arr;

        for (int i = 0; i < small.size(); i++) {
            arr.push_back(small[i]);
        }

        for (int i = 0; i < big.size(); i++) {
            arr.push_back(big[i]);
        }

        if (arr.size() == 0) {
            return nullptr;
        }

        ListNode* ans = new ListNode(arr[0]);
        ListNode* tail = ans;

        for (int i = 1; i < arr.size(); i++) {
            tail->next = new ListNode(arr[i]);
            tail = tail->next;
        }

        return ans;
    }
};