#include <iostream>
using namespace std;

void diagonalMatrix() {
    int n;
    cout << "Enter the rows or columns of the diagonal matrix: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the diagonal matrix:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "The diagonal matrix is:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                cout << arr[i] << " ";
            else
                cout << 0<<" ";
        }
        cout << endl;
    }
}


void triDiagonalMatrix() {
    int n;
    cout << "Enter the rows or columns of the tri-diagonal matrix: ";
    cin >> n;
    int arr_dia[n];
    int arr_upper[n - 1];
    int arr_lower[n - 1];
    cout << "Enter the elements of the diagonal of the tri-diagonal matrix:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr_dia[i];
    }
    cout << "Enter the elements of the upper diagonal of the tri-diagonal matrix:\n";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr_upper[i];
    }
    cout << "Enter the elements of the lower diagonal of the tri-diagonal matrix:\n";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr_lower[i];
    }
    cout << "The tri-diagonal matrix is:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                cout << arr_dia[i] << " ";
            else if (i == j - 1)
                cout << arr_upper[i] << " ";
            else if (i == j + 1)
                cout << arr_lower[j] << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
}

void lowerTriangularMatrix() {
    int n;
    cout << "Enter the rows or columns of the lower triangular matrix: ";
    cin >> n;
    int arr[n * (n + 1) / 2];
    cout << "Enter the elements of the lower triangular matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> arr[i * (i + 1) / 2 + j];
        }
    }
    cout << "The lower triangular matrix is:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j <= i)
                cout << arr[i * (i + 1) / 2 + j] << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
}

void upperTriangularMatrix() {
    int n;
    cout << "Enter the rows or columns of the upper triangular matrix: ";
    cin >> n;
    int arr[n * (n + 1) / 2];
    cout << "Enter the elements of the upper triangular matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cin >> arr[i * n - (i * (i - 1)) / 2 + (j - i)];
        }
    }
    cout << "The upper triangular matrix is:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= i)
                cout << arr[i * n - (i * (i - 1)) / 2 + (j - i)] << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
}

void symmetricMatrix() {
    int n;
    cout << "Enter the rows or columns of the symmetric matrix: ";
    cin >> n;
    int arr[n * (n + 1) / 2];
    cout << "Enter the elements of the symmetric matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> arr[i * (i + 1) / 2 + j];
        }
    }
    cout << "The symmetric matrix is:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j <= i)
                cout << arr[i * (i + 1) / 2 + j] << " ";
            else
                cout << arr[j * (j + 1) / 2 + i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice;
    cout << "Choose the type of matrix to store:\n";
    cout << "1. Diagonal Matrix\n";
    cout << "2. Tri-diagonal Matrix\n";
    cout << "3. Lower Triangular Matrix\n";
    cout << "4. Upper Triangular Matrix\n";
    cout << "5. Symmetric Matrix\n";
    cout << "6. Exit\n";
    cout << "Enter your choice : ";
    cin >> choice;
    while(choice != 6){
    switch (choice) {
        case 1:
            diagonalMatrix();
            break;
        case 2:
            triDiagonalMatrix();
            break;
        case 3:
            lowerTriangularMatrix();
            break;
        case 4:
            upperTriangularMatrix();
            break;
        case 5:
            symmetricMatrix();
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }
    cout << "Enter your choice : ";
    cin >> choice;
}
    return 0;
}