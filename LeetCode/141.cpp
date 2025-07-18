// https://leetcode.com/problems/linked-list-cycle/description/
// Attempt 1: Using a hashmap to store previously visited elements
// Outcome: Accepted
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
    bool hasCycle(ListNode *head) {
        ListNode* temp = head;
        map<ListNode*, int> hashmap;
        while (temp != nullptr){
            if (hashmap.find(temp) != hashmap.end()){
                return true;
            }
            hashmap[temp] = temp->val;
            temp = temp->next;
        }
        return false;
    }
};
// Attempt 2: Using a fast and slow pointer
// Outcome: Accepted
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
    bool hasCycle(ListNode *head) {
        ListNode* first = head;
        ListNode* second = head;
        while (first != nullptr && first->next != nullptr){
            first = first->next->next;
            second = second->next;
            if (first == second){
                return true;
            }
        }
        return false;
    }
};
