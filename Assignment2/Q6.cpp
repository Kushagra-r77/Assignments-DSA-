#include <iostream>
using namespace std;

int main()
{
    int row1, col1, row2, col2;
    cout << "Enter number of rows and columns of first matrix: ";
    cin >> row1 >> col1;
    cout << "Enter number of rows and columns of second matrix: ";
    cin >> row2 >> col2;
    cout << "Enter non-zero elements of first matrix : ";
    int elements1;
    cin >> elements1;
    int matrix1[elements1][3];
    cout << "Enter row, column and value of the elements: \n";
    for (int i = 0; i < elements1; i++){
        cin >> matrix1[i][0] >> matrix1[i][1] >> matrix1[i][2];
    }
    cout << "Enter non-zero elements of second matrix : ";
    int elements2;
    cin >> elements2;
    int matrix2[elements2][3];
    cout << "Enter row, column and value of the elements: \n";
    for (int i = 0; i < elements2; i++){
        cin >> matrix2[i][0] >> matrix2[i][1] >> matrix2[i][2];
    }

    cout << "\nTranspose of first matrix: \n";
    for (int i = 0; i < elements1; i++){
        cout << matrix1[i][1] << " " << matrix1[i][0] << " " << matrix1[i][2] << endl;
    }
    cout << "\nTranspose of second matrix: \n";
    for (int i = 0; i < elements2; i++){
        cout << matrix2[i][1] << " " << matrix2[i][0] << " " << matrix2[i][2] << endl;
    }

    if (row1 != row2 || col1 != col2) {
        cout << "\nAddition not possible as dimensions do not match.\n";
    } else {
        cout << "\nAddition of two matrices: \n";
        int result[elements1 + elements2][3];
        for(int i = 0 ; i < elements1; i++) {
            result[i][0] = matrix1[i][0];
            result[i][1] = matrix1[i][1];
            result[i][2] = matrix1[i][2];
        }
        for(int i = 0 ; i < elements2; i++) {
            bool found = false;
            for(int j = 0 ; j < elements1; j++) {
                if(matrix2[i][0] == result[j][0] && matrix2[i][1] == result[j][1]) {
                    result[j][2] += matrix2[i][2];
                    found = true;
                    break;
                }
            }
            if(!found) {
                result[elements1][0] = matrix2[i][0];
                result[elements1][1] = matrix2[i][1];
                result[elements1][2] = matrix2[i][2];
                elements1++;
            }
        }
    }

    cout << "\nMultiplication of two matrices: \n";
    if (col1 != row2) {
        cout << "Multiplication not possible.\n";
    } else {
        int result_m[row1][col2] = {0};
        for(int i = 0; i < elements1; i++) {
            for(int j = 0; j < elements2; j++) {
                if(matrix1[i][1] == matrix2[j][0]) {
                    result_m[matrix1[i][0]][matrix2[j][1]] += matrix1[i][2] * matrix2[j][2];
                }
            }
        }
        for(int i = 0; i < row1; i++) {
            for(int j = 0; j < col2; j++) {
                if(result_m[i][j] != 0) {
                    cout << i << " " << j << " " << result_m[i][j] << endl;
                }
            }
        }
    }
    
    return 0;
}