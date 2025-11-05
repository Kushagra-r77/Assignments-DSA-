#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}
bool check(Node* head) {
    if (head == NULL) return true;
    Node* temp = head->next;
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }
    return (temp == head);
}
int main() {
    Node* head = NULL;
    insertAtEnd(head, 2);
    insertAtEnd(head, 4);
    insertAtEnd(head, 6);
    insertAtEnd(head, 7);
    insertAtEnd(head, 5);
    if (check(head)) {
        cout << "The linked list is a Circular Linked List." << endl;
    } else {
        cout << "The linked list is not a Circular Linked List." << endl;
    }
}