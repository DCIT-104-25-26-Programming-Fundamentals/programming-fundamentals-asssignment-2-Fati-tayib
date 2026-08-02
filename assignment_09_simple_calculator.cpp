#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

bool divide(double a, double b, double& result) {
    if (b == 0) {
        return false; // signal error to caller
    }
    result = a / b;
    return true;
}

bool modulus(double a, double b, double& result) {
    if (b == 0) {
        return false;
    }
    result = fmod(a, b);
    return true;
}

double exponent(double base, double exp) {
    return pow(base, exp);
}

int main() {
    int choice;

    do {
        cout << "\n============================" << endl;
        cout << "     SIMPLE CALCULATOR" << endl;
        cout << "============================" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Modulus" << endl;
        cout << "6. Exponentiation" << endl;
        cout << "7. Quit" << endl;
        cout << "Select an operation (1-7): ";
        cin >> choice;

        if (choice == 7) {
            cout << "Goodbye!" << endl;
            break;
        }

        if (choice < 1 || choice > 7) {
            cout << "Error: Invalid choice. Please enter 1-7." << endl;
            continue;
        }

        double a, b, result;
        char symbol = '?';
        bool ok = true;

        cout << "Enter first number : ";
        cin >> a;
        cout << "Enter second number: ";
        cin >> b;

        switch (choice) {
            case 1:
                result = add(a, b);
                symbol = '+';
                break;
            case 2:
                result = subtract(a, b);
                symbol = '-';
                break;
            case 3:
                result = multiply(a, b);
                symbol = '*';
                break;
            case 4:
                symbol = '/';
                if (!divide(a, b, result)) {
                    cout << "Error: Cannot divide by zero." << endl;
                    ok = false;
                }
                break;
            case 5:
                symbol = '%';
                if (!modulus(a, b, result)) {
                    cout << "Error: Cannot divide by zero." << endl;
                    ok = false;
                }
                break;
            case 6:
                result = exponent(a, b);
                symbol = '^';
                break;
        }

        if (ok) {
            cout << fixed << setprecision(2);
            cout << "Result: " << a << " " << symbol << " " << b << " = " << result << endl;
        }

    } while (choice != 7);

    return 0;
}
