class Solution {
public:
    int getLength(ListNode* head) {
        int len = 0;
        while (head) { len++; head = head->next; }
        return len;
    }
    void addDeep(ListNode* l1, ListNode* l2, int diff, int& carry) {
        if (!l1) return;
        
        if (diff > 0) {
            addDeep(l1->next, l2, diff - 1, carry);
            int sum = l1->val + carry;
            carry = sum / 10;
            l1->val = sum % 10;
        } else {
            addDeep(l1->next, l2->next, 0, carry);
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            l1->val = sum % 10;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = getLength(l1), len2 = getLength(l2);

        if (len1 < len2) {
            std::swap(l1, l2);
            std::swap(len1, len2);
        }
        
        int carry = 0;
        addDeep(l1, l2, len1 - len2, carry);
 
        if (carry > 0) {
            ListNode* newHead = new ListNode(carry);
            newHead->next = l1;
            return newHead;
        }
        
        return l1;
    }
};