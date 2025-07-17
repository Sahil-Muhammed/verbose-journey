// https://leetcode.com/problems/middle-of-the-linked-list/description/
// Attempt 1: Take count, half it, then traverse linked list again
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
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while (temp != nullptr){
            count++;
            temp = temp->next;
        }
        int mid = count/2;
        ListNode* temp1 = head;
        while (mid--){
            temp1 = temp1->next;
        }
        return temp1;
    }
};
