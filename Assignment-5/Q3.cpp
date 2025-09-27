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

void middle(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    count = count/2;
    for(int i = 0; i<=count;i++){
        head = head->next;
    }
    cout<<head->data;
}
void insert_at_tail(Node* &tail,int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
int main() {
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    insert_at_tail(tail,2);
    insert_at_tail(tail,3);
    insert_at_tail(tail,4);
    insert_at_tail(tail,5);
    return 0;
}