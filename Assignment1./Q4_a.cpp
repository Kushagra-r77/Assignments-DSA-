#include <iostream>
using namespace std;
void reverseArray(int arr[], int size) {
    int si = 0;
    int ei = size - 1;
    while (si < ei){
        int temp = arr[si];
        arr[si] = arr[ei];
        arr[ei] = temp;
        si++;
        ei--;
    }
}
int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin>> size;
    int arr[size];
    cout << "Enter elements of array : ";
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    reverseArray(arr, size);
    
    cout << "Reversed array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}