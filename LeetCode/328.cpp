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
