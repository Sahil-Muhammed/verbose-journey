// https://leetcode.com/problems/reverse-nodes-in-k-group/
// Attempt 1: Reverse the k-sized groups while storing the start and end nodes in an array, then link them properly
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
    ListNode* reverse(ListNode* head, ListNode* end){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while (curr != end){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int i = 0;
        vector<ListNode*> storeHead;
        vector<ListNode*> storeTail;
        ListNode* temp = head;
        ListNode* start = head;
        //ListNode* end = head;
        while (temp){
            i++;
            if (i == k){
                i = 0;
                ListNode* temp1 = temp->next;
                storeHead.push_back(start);
                storeTail.push_back(temp);
                temp = reverse(start, temp1);
                temp->next = temp1;
                start = temp1;
                temp = temp1;
                continue;
            }
            temp = temp->next;
        }
        for (int i = 0; i < storeHead.size() - 1; ++i){
            ListNode* temp = storeHead[i];
            temp->next = storeTail[i+1];
        }
        return storeTail[0];
    }
};
