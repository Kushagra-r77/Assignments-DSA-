
#include <iostream>
using namespace std;
class Node{
  public:
  int data;
  Node* next;
  
  Node(int d){
      this->data=d;
      this->next=NULL;
  }
  ~Node(){
      int value = this->data;
      if(this->next!=NULL){
          this->next = NULL;
      }
      cout<<"Node cleared for value : "<<value<<endl;
  }
};
void insert_at_tail(Node* &tail,int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void delete_node(Node* &head, int value, int &count) {
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL) {
        if (temp->data == value) {
            count++;
            Node* nodeToDelete = temp;
            if (temp == head) {
                head = head->next;
                temp = head; 
            } else {
                prev->next = temp->next;
                temp = temp->next; 
            }

            nodeToDelete->next = NULL;
            delete nodeToDelete;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}
void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
}

int main() {
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    insert_at_tail(tail,2);
    insert_at_tail(tail,1);
    insert_at_tail(tail,2);
    insert_at_tail(tail,1);
    insert_at_tail(tail,3);
    insert_at_tail(tail,1);
    int key;
    cout<<"Enter the key to be deleted : ";
    cin>>key;
    int count = 0;
    delete_node(head,key,count);
    cout<<"Count of occurrences of "<<key<<" is : "<<count<<endl;
    display(head);
    return 0;
}