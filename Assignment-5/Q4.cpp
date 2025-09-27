#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            this->next = NULL;
        }
        cout<<"Linked list element deleted for value : "<<value<<endl;
    }
};
void insert(Node* &head,int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void reverse(Node* &head){
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;
    
    while(curr!=NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<"\t";
        head = head->next;
    }
    cout<<endl;
}

int main() {
    Node* ll = new Node(1);
    Node* head = ll;
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    print(head);
    reverse(head);
    print(head);
    return 0;
}