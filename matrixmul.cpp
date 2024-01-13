#include <iostream>
using namespace std;

const int MAX = 100;

void multiplyMatrices(int mat1[][MAX], int mat2[][MAX], int res[][MAX], int r1, int c1, int r2, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            int sum = 0;
            for (int k = 0; k < c1; k += 4) {
                sum += mat1[i][k] * mat2[k][j];
                sum += mat1[i][k + 1] * mat2[k + 1][j];
                sum += mat1[i][k + 2] * mat2[k + 2][j];
                sum += mat1[i][k + 3] * mat2[k + 3][j];
            }
            res[i][j] = sum;
        }
    }
}

int main() {
    int mat1[MAX][MAX], mat2[MAX][MAX], res[MAX][MAX];
    int r1, c1, r2, c2;

    cout << "Enter the number of rows and columns of matrix 1: ";
    cin >> r1 >> c1;
    cout << "Enter the elements of matrix 1: ";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cin >> mat1[i][j];
        }
    }

    cout << "Enter the number of rows and columns of matrix 2: ";
    cin >> r2 >> c2;
    cout << "Enter the elements of matrix 2: ";
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cin >> mat2[i][j];
        }
    }

    if (c1 != r2) {
        cout << "Matrix multiplication not possible!";
        return 0;
    }

    multiplyMatrices(mat1, mat2, res, r1, c1, r2, c2);

    cout << "Resultant matrix after multiplication: " << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
