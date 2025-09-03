#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        bool distinct = true;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                distinct = false;
                break;
            }
        }
        if (distinct) {
            count++;
        }
    }
    cout << "The total number of distinct elements in the array is: " << count << endl;
    return 0;
}