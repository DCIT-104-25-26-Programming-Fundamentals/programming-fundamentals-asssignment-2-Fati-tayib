#include <iostream>
using namespace std;

int computeSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

double computeAverage(int arr[], int n) {
    return static_cast<double>(computeSum(arr, n)) / n;
}

int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int findMin(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    int n;
    cout << "How many numbers? ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> arr[i];
    }

    cout << "\nResults:" << endl;
    cout << "Sum:     " << computeSum(arr, n) << endl;
    cout << "Average: " << computeAverage(arr, n) << endl;
    cout << "Maximum: " << findMax(arr, n) << endl;
    cout << "Minimum: " << findMin(arr, n) << endl;

    return 0;
}
