#include <iostream>
using namespace std;
class Node {
public:
    char data;
    Node* next;
    Node* prev;
    Node(char val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
void insertAtEnd(Node*& head, char val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
bool check(Node* head) {
    if (head == NULL) return true;
    Node* left = head;
    Node* right = head;
    while (right->next != NULL) {
        right = right->next;
    }
    while (left != right && right->next != left) {
        if (left->data != right->data) {
            return false;
        }
        left = left->next;
        right = right->prev;
    }
    return true;
}
int main() {
    Node* head = NULL;
    insertAtEnd(head, 'l');
    insertAtEnd(head, 'e');
    insertAtEnd(head, 'v');
    insertAtEnd(head, 'e');
    insertAtEnd(head, 'l');
    if (check(head)) {
        cout << "The doubly linked list is a palindrome." << endl;
    } else {
        cout << "The doubly linked list is not a palindrome." << endl;
    }
}