// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
// Attempt 1: Take count and then delete from next iteration
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;
        while (temp != nullptr){
            count++;
            temp = temp->next;
        }
        if (count == 1 && n == 1){
            return nullptr;
        }
        if (count == n){
            ListNode* temp = head->next;
            head->next = nullptr;
            return temp;
        }
        int pos = count-n-1;
        //cout << pos << endl;
        temp = head;
        while (pos > 0){
            //cout << temp->val << endl;
            temp = temp->next;
            pos--;
        }
        temp->next = temp->next->next;
        return head;
    }
};
// Attempt 2: By using a fast and slow pointer, traverse the fast pointer by n steps, then move both fast and slow until fast reaches null, delete from there
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        if (head->next == nullptr){
            return nullptr;
        }
        int count = 0;
        while (count < n){
            fast = fast->next;
            count++;
        }
        if (fast == nullptr){
            return head->next;
        }
        while (fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
