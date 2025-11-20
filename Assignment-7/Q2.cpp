#include <iostream>
using namespace std;
void improvedSelectionSort(int arr[], int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        int minIndex = left;
        int maxIndex = right;

        if (arr[minIndex] > arr[maxIndex]) {
            swap(arr[minIndex], arr[maxIndex]);
        }

        for (int i = left + 1; i < right; i++) {
            if (arr[i] < arr[minIndex]) {
                minIndex = i;
            } else if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }

        swap(arr[left], arr[minIndex]);
        swap(arr[right], arr[maxIndex]);

        left++;
        right--;
    }
}
int main() {
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    improvedSelectionSort(arr, n);

    cout << "Improved Selection Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}