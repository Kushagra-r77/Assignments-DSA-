#include <iostream>
using namespace std;
int find_duplicate(int arr[], int &size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                return j; 
            }
        }
    }
    return -1; 
}
void removeDuplicates(int arr[], int &size){
    int idx = find_duplicate(arr, size);
    while (idx != -1) {
        for (int i = idx; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--; 
        idx = find_duplicate(arr, size);
    }
}
void print(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {1,2,3,2,4,5,1,6,3,9,7,6,2,8};
    int size = sizeof(arr) / sizeof(int);
    
    cout << "Original array: ";
    print(arr, size);
    
    removeDuplicates(arr, size);
    
    cout << "Array after removing duplicates: ";
    print(arr, size);
    
    return 0;
}