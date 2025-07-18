// https://leetcode.com/problems/add-two-numbers/description/
// Attempt 1: Addition by hand with extra node for carry
// Outcome: Accepted
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* prev = nullptr;
        int len1 = 0, len2 = 0;
        int carry = 0;
        while (temp1 && temp2){
            int sum = temp1->val + temp2->val + carry;
            temp1->val = sum % 10;
            temp2->val = temp1->val;
            carry = sum / 10;
            prev = temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
            len1++; len2++;
        }
        while (temp1){
            int sum = temp1->val + carry;
            temp1->val = sum % 10;
            carry = sum / 10;
            prev = temp1;
            temp1 = temp1->next;
            len1++;
        }
        while (temp2){
            int sum = temp2->val + carry;
            temp2->val = sum % 10;
            carry = sum / 10;
            prev = temp2;
            temp2 = temp2->next;
            len2++;
        }
        if (carry > 0){
            ListNode* puthan = new ListNode(carry);
            prev->next = puthan;
        }
        return len1 >= len2 ? l1 : l2;
    }
};
