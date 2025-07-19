// https://leetcode.com/problems/copy-list-with-random-pointer/description/
// Attempt 1: Create separate nodes (w/o) links while iterating first time and store the correspondence in a hashmap, next iteration will create links
// Outcome: Accepted
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> hashmap;
        Node* temp = head;
        hashmap[nullptr] = nullptr;
        while (temp){
            Node* puthan = new Node(temp->val);
            hashmap[temp] = puthan;
            temp = temp->next;
        }
        temp = head;
        while (temp){
            hashmap[temp]->next = hashmap[temp->next];
            hashmap[temp]->random = hashmap[temp->random];
            temp = temp->next;
        }
        return hashmap[head];
    }
};
// Attempt 2: Inserting the newly created nodes in between the existing linked lists, random pointers made in next iteration as next of existing list's random, and another iteration to separate the linked lists
// Outcome: Accepted
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        if (!head){
            return nullptr;
        }
        while (temp){
            Node* puthan = new Node(temp->val);
            puthan->next = temp->next;
            temp->next = puthan;
            temp = puthan->next;
        }

        temp = head;
        while (temp){
            if (temp->random == nullptr){
                temp->next->random = nullptr;
                temp = temp->next->next;
                continue;
            }
            temp->next->random = temp->random->next;
            temp = temp->next->next;
        }

        Node* cloneHead = head->next;
        Node* newTemp = new Node(-1);
        temp = head;
        while (temp){
            newTemp->next = temp->next;
            newTemp = newTemp->next;
            temp->next = newTemp->next;
            temp = temp->next;
        }
        return cloneHead;
    }
};
