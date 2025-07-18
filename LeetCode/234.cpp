// https://leetcode.com/problems/palindrome-linked-list/description/
// Attempt 1: Using a string to store and checking if the string is a palindrome
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
    bool numPal(string s){
        int low = 0, high = s.size() - 1;
        while (low <= high){
            if (s[low] == s[high]){
                low++;
                high--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        string s;
        ListNode* temp = head;
        while (temp != nullptr){
            s += (char)temp->val;
            temp = temp->next;
        }
        return numPal(s);
    }
};
// Attempt 2: Using reversal of linked list from half and then comparing
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
    ListNode* reverse(ListNode* head){
        if (head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* temp = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return temp;
    }
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr){
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rev = reverse(slow->next);
        ListNode* first = head;
        ListNode* second = rev;
        while (second != nullptr){
            if (second->val == first->val){
                ;
            }
            else{
                return false;
            }
            second = second->next;
            first = first->next;
        }
        return true;
    }
};
