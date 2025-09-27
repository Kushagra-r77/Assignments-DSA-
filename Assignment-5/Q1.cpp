#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node (int data){
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            this -> next = NULL;
        }
        cout<<"Memory is free for node with data "<<value<<endl;
    }
};
void insert_at_head(Node* &head,int d){
    
    Node* new_node = new Node(d);
    new_node->next = head;
    head = new_node;
}

void insert_at_end(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void insert_after_value(Node* &head, int d,int ele){
    Node* temp = new Node(d);
    Node* curr = head;
    while(curr->data != ele){
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
}
void delete_from_beg(Node* &head, Node* &tail) {
    if (head == NULL) {
        cout << "List is empty, nothing to delete.\n";
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

void delete_from_end(Node* &tail, Node* &head) {
    if (head == NULL) { 
        cout << "List is empty, nothing to delete.\n";
        return;
    }

    if (head->next == NULL) { 
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    Node* curr = head;
    Node* prev = NULL;
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;
    tail = prev;
    delete curr;
}
void display_pos(Node* head, int ele) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == ele) {
            cout << "Element " << ele << " is found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Element " << ele << " is not found in the list" << endl;
}
void print(Node* head){
    while(head != NULL){
        cout<<head->data<<"  ";
        head = head->next;
    }
    cout<<endl;
}
void delete_by_value(Node* &head, Node* &tail, int value) {
    if (head == NULL) {
        cout << "List is empty, nothing to delete.\n";
        return;
    }

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL; 
        }
        delete temp;
        return;
    }

    Node* curr = head;
    Node* prev = NULL;
    while (curr != NULL && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        cout << "Element " << value << " not found in the list.\n";
        return;
    }

    prev->next = curr->next;
    if (curr->next == NULL) {
        tail = prev; 
    }
    delete curr;
}

int main(){
    cout<<"Enter Your Choice: "<<endl;
    cout<<"1. Insertion at the beginning."<<endl;
    cout<<"2. Insertion at the end."<<endl;
    cout<<"3. Insertion in between after a node."<<endl;
    cout<<"4. Deletion from the beginning."<<endl;
    cout<<"5. Deletion from the end."<<endl;
    cout<<"6. Deletion of a specific node."<<endl;
    cout<<"7. Search for a node and display its position from head."<<endl;
    cout<<"8. Display all the node values."<<endl;
    cout<<"9. Exit"<<endl;
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    int choice;
    cin>>choice;
    while(choice!=9){
        switch(choice){
            case 1: {
                int val;
                cout<<"Enter the value to insert at the beginning: ";
                cin>>val;
                insert_at_head(head,val);
                break;
            }
            case 2: {
                int val;
                cout<<"Enter the value to insert at the end: ";
                cin>>val;
                insert_at_end(tail,val);
                break;
            }
            case 3: {
                int val, after_val;
                cout<<"Enter the value to insert: ";
                cin>>val;
                cout<<"Enter the value after which to insert: ";
                cin>>after_val;
                insert_after_value(head,val,after_val);
                break;
            }
            case 4: {
                delete_from_beg(head,tail);
                break;
            }
            case 5: {
                delete_from_end(tail,head);
                break;
            }
            case 6: {
                int val;
                cout<<"Enter the value to delete: ";
                cin>>val;
                delete_by_value(head,tail,val);
                break;
            }
            case 7: {
                int val;
                cout<<"Enter the value to search: ";
                cin>>val;
                display_pos(head,val);
                break;
            }
            case 8: {
                print(head);
                break;
            }
            default:
                cout<<"Invalid choice !!!!!"<<endl;
        }
        cout<<"Enter Your Choice: "<<endl;
        cin>>choice;
    }
}