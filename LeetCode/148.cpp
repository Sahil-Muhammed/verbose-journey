// https://leetcode.com/problems/sort-list/description/
// Attempt 1: Store in array and sort, then update the linked list
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
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while (temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        sort(arr.begin(), arr.end());
        temp = head;
        int i = 0;
        while (temp){
            temp->val = arr[i++];
            temp = temp->next;
        }
        return head;
    }
};
// Attempt 2: Using merge sort, sort the linked list
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
    ListNode* merge(ListNode* head1, ListNode* head2){
        if (head1 == nullptr){
            return head2;
        }
        if (head2 == nullptr){
            return head1;
        }
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;
        ListNode* newHead = new ListNode(0);
        ListNode* temp3 = newHead;
        while (temp1 && temp2){
            if (temp1->val < temp2->val){
                temp3->next = temp1;
                temp1 = temp1->next;
                temp3 = temp3->next;
            }
            else{
                temp3->next = temp2;
                temp2 = temp2->next;
                temp3 = temp3->next;
            }
        }
        while (temp1){
            temp3->next = temp1;
            temp1 = temp1->next;
            temp3 = temp3->next;
        }
        while (temp2){
            temp3->next = temp2;
            temp2 = temp2->next;
            temp3 = temp3->next;
        }
        return newHead->next; // because newHead is a dummy node with value 0
    }
    ListNode* divide(ListNode* head){
        if (!head){
            return nullptr;
        }
        if (!(head->next)){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr; // new link
        ListNode* left = divide(head);
        ListNode* right = divide(mid);
        return merge(left, right);
    }
    ListNode* sortList(ListNode* head) {
        return divide(head);
    }
};
