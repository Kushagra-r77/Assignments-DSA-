#include <iostream>
using namespace std;

int main(){
    int arr[50] = {0};
    int size = 5,idx,ele;
    int choice = 0;
    while (choice!=6){
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter 5 integers: ";
                for(int i = 0; i < size; i++){
                    cin >> arr[i];
                }
                break;
            case 2:
                cout << "Array elements: ";
                for(int i = 0; i < size; i++){
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;
            case 3:
                    cout << "Enter element to insert: ";
                    cin >> ele;
                    cout << "Enter index to insert at : ";
                    cin >> idx;
                        for(int i = size; i > idx; i--) {
                            arr[i] = arr[i - 1];
                        }
                        arr[idx] = ele;
                        size++;
                    break;
            case 4:
                cout << "Enter index to delete: ";
                cin >> idx;
                    for(int i = idx; i < size - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    size--;
                
                break;
            case 5:
                cout << "Enter element to search: ";
                cin >> ele;
                bool check = false;
                for(int i = 0; i < size; i++) {
                    if(arr[i] == ele) {
                        cout << "Element found at index: " << i << endl;
                        check = true;
                        break;
                    }
                }
                if(check!= true) {
                    cout << "Element not found in the array." << endl;
                }
                    
        }
    }
    return 0;
}