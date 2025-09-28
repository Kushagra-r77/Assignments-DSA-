#include <iostream> 
using namespace std;
#define MAX 8
class Queue {
    public:
    int arr[MAX];
    int front, rear;
    Queue() { front = -1; rear = -1; }
};

bool isFull(Queue q) {
    if ((q.rear + 1) % MAX == q.front){
        return true;}
    else{
        return false;}
}
bool isEmpty(Queue q) {
    if(q.front == -1 || q.rear==-1){
        return true;
    }
    else{
        return false;
    }
}
void enqueue(Queue &q, int x) {
    if (isFull(q)){
        cout << "OVERFLOW\n";
    }
    else{
        if(q.front == -1){
            q.front = 0;
        }
        q.rear = (q.rear + 1) % MAX;
        q.arr[q.rear] = x;
    }
}
void dequeue(Queue &q) {
    if (isEmpty(q)){
        cout << "UNDERFLOW\n";
    }
    else{
        cout << q.arr[q.front] << endl;
        if(q.front == q.rear){
            q.front = -1;
            q.rear = -1;
        }
        else{
            q.front = (q.front + 1) % MAX;
        }
    }
}
void peek(Queue q){
    if (isEmpty(q)){
        cout << "Queue is empty\n";
    }
    else{
        cout << q.arr[q.front] << endl;
    }
}
void display(Queue q){
    if (isEmpty(q)){
        cout << "Queue is empty\n";
    }
    else{
        int i = q.front;
        while(true){
            cout << q.arr[i] << " ";
            if(i == q.rear){
                break;
            }
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
}
int main(){
    Queue q;
    int choice=0, x;
    while (choice != 7 ) {
        cout << "1. Enqueue\n2. Dequeue\n3. Is Empty\n4. Is Full\n5. Display\n6. Peek\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> x;
                enqueue(q, x);
                break;
            case 2:
                cout << "Dequeued value: ";
                dequeue(q);
                break;
            case 3:
                if (isEmpty(q)){
                    cout << "Queue is empty\n";
                }
                else{
                    cout << "Queue is not empty\n";
                }
                break;
            case 4:
                if (isFull(q)){
                    cout << "Queue is full\n";
                }
                else{
                    cout << "Queue is not full\n";
                }
                break;
            case 5:
                cout << "Queue elements: ";
                display(q);
                break;
            case 6:
                cout << "Front element: ";
                peek(q);
                break;
            case 7:
                cout << "Exit\n";
            default:
                cout << "Invalid choice\n";
        }
    }
    return 0;
}