// https://leetcode.com/problems/intersection-of-two-linked-lists/description/
// Attempt 1: Using a set data structure to store previously visited elements
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        unordered_set<ListNode*> hashset;
        while (temp1){
            hashset.insert(temp1);
            temp1 = temp1->next;
        }
        while (temp2){
            if (hashset.find(temp2) != hashset.end()){
                return temp2;
            }
            temp2 = temp2->next;
        }
        return nullptr;
    }
};
// Attempt 2: Traversing the linked lists and restarting from opposite heads when the end is reached
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        while (temp1 != temp2){
            temp1 = temp1 == nullptr ? headB : temp1->next;
            temp2 = temp2 == nullptr ? headA : temp2->next;
        }
        return temp1;
    }
};
