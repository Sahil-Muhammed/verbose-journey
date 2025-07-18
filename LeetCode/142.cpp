// https://leetcode.com/problems/linked-list-cycle-ii/description/
// Attempt 1: Using a hashmap to store count of previous element
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp = head;
        map<ListNode*, int> hashmap;
        while (temp != nullptr){
            if (hashmap.find(temp->next) != hashmap.end()){
                return temp->next;
            }
            hashmap[temp] = 1;
            temp = temp->next;
        }
        return nullptr;
        // slow dist = d + loop meet
        // fast dist = d + loop meet
    }
};
// Attempt 2: Using fast and slow pointers
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            //cout << slow->val << " " << fast->val << endl;
            if (slow == fast){
                slow = head;
                while (slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
