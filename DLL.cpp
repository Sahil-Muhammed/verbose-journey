#include <bits/stdc++.h>
class Node{
    public:
        int data;
        Node* next;
        Node* prev;
    public:
        Node(int data1, Node* next1, Node* prev1){
            data = data1;
            next = next1;
            prev = prev1;
        }
        Node(int data1, Node* prev1){
            data = data1;
            prev = prev1;
            next = nullptr;
        }
};
Node* convertToDLL(std::vector<int> arr){
    Node* head = new Node(arr[0], nullptr, nullptr);
    Node* prev = head;
    for (int i = 1; i < arr.size(); ++i){
        Node* temp = new Node(arr[i], nullptr, prev);
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
Node* deleteHead(Node* head){
    if (!head || !(head->next)){
        return nullptr;
    }
    Node* newHead = head->next;
    newHead->prev = nullptr;
    head->next = nullptr;
    return newHead;
}
Node* deleteTail(Node* head){
    if (!head || !(head->next)){
        return nullptr;
    }
    Node* temp = head;
    while (temp->next){
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    temp->prev = nullptr;
    return head;
}
Node* deleteKthNode(Node* head, int k){
    int count = 0;
    Node* temp = head;
    while (temp){
        count++;
        if (count == k){
            break;
        }
        temp = temp->next;
    }
    Node* prev = temp->prev;
    Node* next = temp->next;
    if (!prev && !next){
        return nullptr;
    }
    else if (!prev){
        return deleteHead(temp);
    }
    else if (!next){
        return deleteTail(temp);
    }
    prev->next = next;
    next->prev = prev;
    free(temp);
    return head;
}
void deleteNode(Node* temp){
    Node* prev = temp->prev;
    Node* next = temp->next;
    if (!prev && !next){
        temp = nullptr;
        return;
    }
    if (!prev){
        Node* newHead = next;
        newHead->prev = nullptr;
        temp->next = nullptr;
        return;
    }
    if (!next){
        Node* newHead = prev;
        prev->next = nullptr;
        temp->prev = nullptr;
        return;
    }
    prev->next = next;
    next->prev = prev;
}
Node* insertBeforeHead(Node* head, int num){
    Node* puthan = new Node(num, head, nullptr);
    head->prev = puthan;
    return puthan;
}
Node* insertAfterTail(Node* head, int num){
    Node* temp = head;
    while (temp->next){
        temp = temp->next;
    }
    Node* puthan = new Node(num, nullptr, temp);
    temp->next = puthan;
    return head;
}
Node* insertAtK(Node* head, int pos, int num){
    int count = 0;
    Node* temp = head;
    if (pos == 0){
        return insertBeforeHead(head, num);
    }
    while (temp){
        count++;
        if (count == pos){
            break;
        }
        temp = temp->next;
    }
    if (!temp){
        return insertAfterTail(head, num);
    }
    Node* puthan = new Node(num, temp, temp->prev);
    temp->prev->next = puthan;
    temp->prev = puthan;
    return head;
}
int main(){
    std::vector<int> arr = {2, 4, 5, 7, 9};
    Node* temp = convertToDLL(arr);
    PrintLL(temp);
    temp = insertBeforeHead(temp, 0);
    temp = insertAfterTail(temp, 10);
    temp = insertAtK(temp, 9, 3);
    PrintLL(temp);
    return 0;
}
