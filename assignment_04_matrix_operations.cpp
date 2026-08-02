#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX = 10;

// -----------------------------------------------------------------------------
// Helper functions (read/print) — used by all three parts
// -----------------------------------------------------------------------------
void readMatrix(int matrix[MAX][MAX], int rows, int cols, const string& name) {
    cout << "Enter values for matrix " << name << ":" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// -----------------------------------------------------------------------------
// PART A — Transpose
// -----------------------------------------------------------------------------
void transposeMatrix(int matrix[MAX][MAX], int rows, int cols, int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// -----------------------------------------------------------------------------
// PART B — Addition
// -----------------------------------------------------------------------------
void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int rows, int cols, int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// -----------------------------------------------------------------------------
// PART C — Multiplication
// -----------------------------------------------------------------------------
void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int m, int n, int p, int result[MAX][MAX]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// -----------------------------------------------------------------------------
// main — menu-driven so each part can be tested independently
// -----------------------------------------------------------------------------
int main() {
    int choice;
    cout << "Matrix Operations Menu" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Enter choice (1-3): ";
    cin >> choice;

    if (choice == 1) {
        int rows, cols;
        int matrix[MAX][MAX], result[MAX][MAX];

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        readMatrix(matrix, rows, cols, "A");
        transposeMatrix(matrix, rows, cols, result);

        cout << "\nOriginal Matrix:" << endl;
        printMatrix(matrix, rows, cols);
        cout << "\nTransposed Matrix:" << endl;
        printMatrix(result, cols, rows);

    } else if (choice == 2) {
        int rows, cols;
        int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        readMatrix(a, rows, cols, "A");
        readMatrix(b, rows, cols, "B");
        addMatrices(a, b, rows, cols, result);

        cout << "\nSum Matrix:" << endl;
        printMatrix(result, rows, cols);

    } else if (choice == 3) {
        int m, n, p;
        int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];

        cout << "Enter rows of A (M): ";
        cin >> m;
        cout << "Enter columns of A / rows of B (N): ";
        cin >> n;
        cout << "Enter columns of B (P): ";
        cin >> p;

        readMatrix(a, m, n, "A");
        readMatrix(b, n, p, "B");
        multiplyMatrices(a, b, m, n, p, result);

        cout << "\nProduct Matrix (A x B):" << endl;
        printMatrix(result, m, p);

    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
