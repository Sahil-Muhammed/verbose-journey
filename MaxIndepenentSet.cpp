#include <bits/stdc++.h>
// Maximum Independent Set on trees
using namespace std;
class Node{
    public:
    int num;
    Node* left;
    Node* right;
    Node* parent;
};

Node* newNode(int num){
    Node* temp = new Node();
    temp->num = num;
    temp->parent = NULL;
    temp->left = temp->right = NULL;
    return temp;
}

void setChild(Node* parent, Node* child, bool isLeft) {
    if (child != NULL) {
        child->parent = parent;
    }
    if (isLeft) {
        parent->left = child;
    } else {
        parent->right = child;
    }
}
Node* deleteNode(Node* root){
    if (root == NULL) {
        return NULL;
    }

    // Get the parent before deleting the node
    Node* parent = root->parent;

    // Handle the case where root has a parent
    if (parent != NULL) {
        // Detach root from parent
        if (parent->left == root) {
            parent->left = NULL;
        } else if (parent->right == root) {
            parent->right = NULL;
        }

        // If parent has another child, update that child's parent pointer
        if (parent->left != NULL) {
            parent->left->parent = parent->parent;
        }
        if (parent->right != NULL) {
            parent->right->parent = parent->parent;
        }

        // Update grandparent's child pointer
        if (parent->parent != NULL) {
            if (parent->parent->left == parent) {
                parent->parent->left = (parent->left != NULL) ? parent->left : parent->right;
            } else {
                parent->parent->right = (parent->left != NULL) ? parent->left : parent->right;
            }
        }

        delete parent;
    }

    // Delete the root node's children connections
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;

    // Delete the node itself
    delete root;

    return NULL;
}
void printTree(Node* root) {
    if (root == NULL) return;

    cout << "Node: " << root->num << " ";
    if (root->parent) cout << "Parent: " << root->parent->num << " ";
    if (root->left) cout << "Left: " << root->left->num << " ";
    if (root->right) cout << "Right: " << root->right->num;
    cout << endl;

    printTree(root->left);
    printTree(root->right);
}
int MaxIndepSet(vector<int>& set, Node* root, bool includeParent = true) {
    if (root == NULL) {
        return 0;
    }

    // Case 1: Include current node
    int withNode = 1;  // Count current node
    if (root->left) {
        withNode += MaxIndepSet(set, root->left->left, true);
        withNode += MaxIndepSet(set, root->left->right, true);
    }
    if (root->right) {
        withNode += MaxIndepSet(set, root->right->left, true);
        withNode += MaxIndepSet(set, root->right->right, true);
    }

    // Case 2: Exclude current node
    int withoutNode = 0;
    if (includeParent) {  // Only consider children if parent wasn't included
        if (root->left) {
            withoutNode += MaxIndepSet(set, root->left, false);
        }
        if (root->right) {
            withoutNode += MaxIndepSet(set, root->right, false);
        }
    }

    if (withNode > withoutNode) {
        set.push_back(root->num);
        return withNode;
    }
    return withoutNode;
}
int main(){
    Node *root = newNode(20);
    Node *node8 = newNode(8);
    Node *node4 = newNode(4);
    Node *node12 = newNode(12);
    Node *node10 = newNode(10);
    Node *node14 = newNode(14);
    Node *node22 = newNode(22);
    Node *node25 = newNode(25);
    
    setChild(root, node8, true);   // set node8 as left child of root
    setChild(root, node22, false); // set node22 as right child of root
    setChild(node8, node4, true);  // set node4 as left child of node8
    setChild(node8, node12, false);// set node12 as right child of node8
    setChild(node12, node10, true);// set node10 as left child of node12
    setChild(node12, node14, false);// set node14 as right child of node12
    setChild(node22, node25, false);// set node25 as right child of node22
    printTree(root);
    
    vector<int> mis;
    int maxSize = MaxIndepSet(mis, root);
    cout << "The size of maximum independent set is " << maxSize << endl;
    for (int i = 0; i < mis.size(); ++i){
        cout << mis[i] << " ";
    }
    cout << endl;
    return 0;
}
