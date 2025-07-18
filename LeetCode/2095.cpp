// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/
// Attempt 1: Brute force
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
    ListNode* deleteMiddle(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        if (head == nullptr || head->next == nullptr){
            return nullptr;
        }
        while (temp){
            temp = temp->next;
            count++;
        }
        int half = count/2 - 1;
        temp = head;
        while (half--){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};
// Attempt 2: Using a fast and slow pointer to reach midway and then deleteMiddle
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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* first = head;
        ListNode* second = head;
        if (!(head->next)){
            return nullptr;
        }
        second = second->next->next;
        while (second && second->next){
            second = second->next->next;
            first = first->next;
        }
        first->next = first->next->next;
        return head;
    }
};
