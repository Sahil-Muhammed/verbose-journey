#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
    public:
        Node(int data1, Node* next1){
            data = data1;
            next = next1;
        }
};
Node* convertArrToLL(vector<int> arr){
    Node* head = new Node(arr[0], nullptr);
    Node* mover = head;
    for (int i = 1; i < arr.size(); ++i){
        Node* temp = new Node(arr[i], nullptr);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
int lenLL(Node* head){
    int count = 0;
    Node* temp = head;
    while (temp != nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}
int main(){
    vector<int> arr = {1, 3, 4, 6, 7};
    Node* head = convertArrToLL(arr);
    //cout << head->data << " " << head->next->data << endl;
    Node* temp = head;
    while (temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    int len = lenLL(head);
    cout << "Length of linked list is " << len << endl;
    return 0;
}
