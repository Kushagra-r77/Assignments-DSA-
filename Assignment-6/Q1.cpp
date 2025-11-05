#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
void insertAtBeginning_circular(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head==NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}
void insertAtEnd_circular(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head==NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}
void insertAfterNode_circular(Node*& head, int target, int val) {
    if (head==NULL) return;
    Node* temp = head;
    do {
        if (temp->data == target) {
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);
}
void deleteNode_circular(Node*& head, int target) {
    if (head==NULL) return;
    Node *curr = head, *prev = NULL;
    do {
        if (curr->data == target) {
            if (prev != NULL) {
                prev->next = curr->next;
            } else {
                Node* temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                if (curr->next == head) {
                    head = NULL;
                } else {
                    temp->next = curr->next;
                    head = curr->next;
                }
            }
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);
}
void searchNode_circular(Node* head, int target) {
    if (head==NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    do {
        if (temp->data == target) {
            cout << "Node " << target << " found in the linked list." << endl;
            return;
        }
        temp = temp->next;
    } while (temp != head);
    cout << "Node " << target << " not found in the linked list." << endl;
}
void display_circular(Node* head) {
    if (head==NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
void insertAtBeginning_doubly(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head!=NULL) {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
}
void insertAtEnd_doubly(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head==NULL) {
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
void insertAfterNode_doubly(Node*& head, int target, int val) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == target) {
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != NULL) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    }
}
void deleteNode_doubly(Node*& head, int target) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == target) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            } else {
                head = temp->next;
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            delete temp;
            return;
        }
        temp = temp->next;
    }
}
void searchNode_doubly(Node* head, int target) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == target) {
            cout << "Node " << target << " found in the linked list." << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Node " << target << " not found in the linked list." << endl;
}
void display_doubly(Node* head) {
    if (head==NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    cout << "Doubly Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    Node* circularHead = NULL;
    Node* doublyHead = NULL;
    int choice;
    while(choice != -1){
        cout<<"Menu:\n1. Insert at beginning (Circular)\n2. Insert at end (Circular)\n3. Insert after node (Circular)\n4. Delete node (Circular)\n5. Search node (Circular)\n6. Display (Circular)\n7. Insert at beginning (Doubly)\n8. Insert at end (Doubly)\n9. Insert after node (Doubly)\n10. Delete node (Doubly)\n11. Search node (Doubly)\n12. Display (Doubly)\n-1. Exit\nEnter your choice: ";
        cin>>choice;
        int val, target;
        switch(choice){
            case 1:
                cout<<"Enter value to insert at beginning (Circular): ";
                cin>>val;
                insertAtBeginning_circular(circularHead, val);
                break;
            case 2:
                cout<<"Enter value to insert at end (Circular): ";
                cin>>val;
                insertAtEnd_circular(circularHead, val);
                break;
            case 3:
                cout<<"Enter target node and value to insert after (Circular): ";
                cin>>target>>val;
                insertAfterNode_circular(circularHead, target, val);
                break;
            case 4:
                cout<<"Enter value of node to delete (Circular): ";
                cin>>target;
                deleteNode_circular(circularHead, target);
                break;
            case 5:
                cout<<"Enter value of node to search (Circular): ";
                cin>>target;
                searchNode_circular(circularHead, target);
                break;
            case 6:
                display_circular(circularHead);
                break;
            case 7:
                cout<<"Enter value to insert at beginning (Doubly): ";
                cin>>val;
                insertAtBeginning_doubly(doublyHead, val);
                break;
            case 8:
                cout<<"Enter value to insert at end (Doubly): ";
                cin>>val;
                insertAtEnd_doubly(doublyHead, val);
                break;
            case 9:
                cout<<"Enter target node and value to insert after (Doubly): ";
                cin>>target>>val;
                insertAfterNode_doubly(doublyHead, target, val);
                break;
            case 10:
                cout<<"Enter value of node to delete (Doubly): ";
                cin>>target;
                deleteNode_doubly(doublyHead, target);
                break;
            case 11:
                cout<<"Enter value of node to search (Doubly): ";
                cin>>target;
                searchNode_doubly(doublyHead, target);
                break;
            case 12:
                display_doubly(doublyHead);
                break;
            case -1:
                cout<<"Exit"<<endl;
                break;
            default:
                cout<<"Invalid choice !!!"<<endl;
        }
    }
}