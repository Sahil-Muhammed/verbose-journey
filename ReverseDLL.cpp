#include <bits/stdc++.h>
class Node{
    public:
        int data;
        Node* next;
        Node* prev;
    public:
        Node(int data1, Node* prev1, Node* next1){
            data = data1;
            prev = prev1;
            next = next1;
        }
};
Node* convertToDLL(std::vector<int> arr){
    Node* head = new Node(arr[0], nullptr, nullptr);
    Node* prev = head;
    for (int i = 1; i < arr.size(); ++i){
        Node* temp = new Node(arr[i], prev, nullptr);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
void PrintLL(Node* head){
    Node* temp = head;
    if (!head){
        return;
    }
    while (temp->next){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << temp->data << std::endl;
    while (temp){
        std::cout << temp->data << " ";
        temp = temp->prev;
    }
    std::cout << std::endl;
}
Node* reverseByStack(Node* head){
    std::stack<int> stk;
    Node* temp = head;
    PrintLL(head);
    while (temp){
        stk.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp){
        temp->data = stk.top();
        stk.pop();
        temp = temp->next;
    }
    return head;
}
Node* reverseSinglePass(Node* head){
    Node* temp = head;
    Node* prev = nullptr;
    while (temp){
        prev = temp->prev;
        temp->prev = temp->next;
        temp->next = prev;
        temp = temp->prev;
    }
    return prev->prev;
}
int main(){
    std::vector<int> arr = {1, 2, 4, 6, 8};
    Node* head = convertToDLL(arr);
    head = reverseSinglePass(head);
    PrintLL(head);
    return 0;
}
