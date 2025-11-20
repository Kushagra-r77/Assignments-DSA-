#include <iostream>
using namespace std;
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int* L = new int[n1];
        int* R = new int[n2];
        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];
        int i = 0;
        int j = 0;
        int k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
        delete[] L;
        delete[] R;
    }
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main(){
    int arr[] = {5,4,3,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    int selArr[] = {5,4,3,2,1};
    selectionSort(selArr, n);
    cout << "Selection Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << selArr[i] << " ";
    cout << endl;

    int insArr[] = {5,4,3,2,1};
    insertionSort(insArr, n);
    cout << "Insertion Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << insArr[i] << " ";
    cout << endl;

    int bubArr[] = {5,4,3,2,1};
    bubbleSort(bubArr, n);
    cout << "Bubble Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << bubArr[i] << " ";
    cout << endl;

    int merArr[] = {5,4,3,2,1};
    merge_sort(merArr, 0, n - 1);
    cout << "Merge Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << merArr[i] << " ";
    cout << endl;

    int quiArr[] = {5,4,3,2,1};
    quickSort(quiArr, 0, n - 1);
    cout << "Quick Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << quiArr[i] << " ";
    cout << endl;

    return 0;
}