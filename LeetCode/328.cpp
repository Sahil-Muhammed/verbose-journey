// https://leetcode.com/problems/odd-even-linked-list/description/
// Attempt 1: Using an array to store even and odd elements and then updating while traversing again
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
    ListNode* oddEvenList(ListNode* head) {
        vector<int> odd, even;
        int flag = 1;
        for (ListNode* temp = head; temp != nullptr; temp = temp->next){
            if (flag%2 == 0){
                flag++;
                even.push_back(temp->val);
            }
            else{
                flag++;
                odd.push_back(temp->val);
            }
        }
        flag = 1;
        int i = 0, j = 0;
        ListNode* temp1 = head;
        while (j < odd.size()){
            temp1->val = odd[j++];
            temp1 = temp1->next;
        }
        while (i < even.size()){
            temp1->val = even[i++];
            temp1 = temp1->next;
        }
        return head;
    }
};
// Attempt 2: Changing links in every iteration to create two separate linked lists and then linking them in the end
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !(head->next) || !(head->next->next)){
            return head;
        }
        ListNode* temp = head;
        ListNode* head2 = head->next;
        ListNode* temp1 = head2;
        temp->next = temp->next->next;
        temp = temp->next;
        while (temp != nullptr && temp->next != nullptr){
            temp1->next = temp->next;
            temp1 = temp1->next;
            if (temp->next->next == nullptr){
                temp->next = head2;
                break;
            }
            else{
                temp->next = temp->next->next;
            }
            temp = temp->next;
        }
        temp1->next = nullptr;
        temp->next = head2;
        return head;
    }
};
