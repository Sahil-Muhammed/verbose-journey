// https://leetcode.com/problems/rotate-list/description/
//
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 1;
        if (!head || k == 0){
            return head;
        }
        while (temp->next){
            count++;
            temp = temp->next;
        }
        ListNode* tail = temp;
        cout << tail->val << endl;
        k = k%count;
        if (k == 0){
            return head;
        }
        //k--;
        temp = head;
        for (int i = 0; i < count - k - 1; ++i){
            temp = temp->next;
        }
        ListNode* temp1 = temp->next;
        temp->next = nullptr;
        tail->next = head;
        return temp1;
    }
};
