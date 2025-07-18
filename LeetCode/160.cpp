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
        set<ListNode*> hashset;
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