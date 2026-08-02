#include <iostream>
#include <iomanip>
using namespace std;

// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
void printTable(int num) {
    cout << "Multiplication Table for " << num << ":" << endl;
    for (int i = 1; i <= 12; i++) {
        cout << num << "  x  " << setw(2) << i << "  =  " << (num * i) << endl;
    }
}

// -----------------------------------------------------------------------------
// PART B — Tables from 1 to N
// -----------------------------------------------------------------------------
void printTablesUpTo(int n) {
    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return;
    }

    for (int num = 1; num <= n; num++) {
        printTable(num);
        if (num != n) {
            cout << "---------------------------" << endl;
        }
    }
}

int main() {
    int choice;
    cout << "1. Single Table" << endl;
    cout << "2. Tables from 1 to N" << endl;
    cout << "Enter choice (1-2): ";
    cin >> choice;

    if (choice == 1) {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        printTable(num);

    } else if (choice == 2) {
        int n;
        cout << "Enter a number: ";
        cin >> n;
        printTablesUpTo(n);

    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
