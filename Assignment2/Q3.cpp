#include <iostream>
using namespace std;
int Linear(int arr[], int n) {
    for (int i = 0; i < n ; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }
    return -1; 
}
int Binary(int arr[], int n) {
    int si = 0, ei = n - 1; 
    while (si <= ei) {
        int mid = (ei + si) / 2;
        if (arr[mid] != mid + 1) {
            if (mid == 0 || arr[mid - 1] == mid) {
                return mid + 1;
            }
            ei = mid - 1;
        } else {
            si = mid + 1;
        }
    }
    return -1;
}
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }
    int ml = Linear(arr, n);
    if (ml != -1) {
        cout << "Missing number (Linear Search): " << ml << endl;
    } else {
        cout << "No missing number found (Linear Search)." << endl;
    }
    int mb = Binary(arr, n);
    if (mb != -1) {
        cout << "Missing number (Binary Search): " << mb << endl;
    } else {
        cout << "No missing number found (Binary Search)." << endl;
    }
    return 0;
}