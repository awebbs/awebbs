 This code is a program to find the largest proper divisor of a number.
// It includes two functions: largest_proper_divisor and process_input.

#include <iostream>
#include <stdexcept>

// Use the std namespace.
using namespace std;

// Function to find the largest proper divisor of a number.
// If n is 0 or 1, it throws an invalid_argument exception.
// Otherwise, it iterates through numbers from n/2 to 1,
// and returns the first number that divides n.
// If no such number is found, it returns -1 (which will never happen).
int largest_proper_divisor(int n) {
    if (n == 0) {
        throw invalid_argument("largest proper divisor is not defined for n=0");
    }
    if (n == 1) {
        throw invalid_argument("largest proper divisor is not defined for n=1");
    }
    for (int i = n/2; i >= 1; --i) {
        if (n % i == 0) {
            return i;
        }
    }
    return -1; // will never happen
}

// Function to process the input and call the largest_proper_divisor function.
// It catches the invalid_argument exception thrown by largest_proper_divisor
// and prints the error message.
void process_input(int n) {
    try {
    int d = largest_proper_divisor(n); 
    cout << "result=" << d << endl; 
    }
    catch (const std::invalid_argument& ia) {
        cout << ia.what() << endl;
    }
    cout << "returning control flow to caller" << endl;
}


// Main function to get the input and call the process_input function.
int main() {
    int n;
    cin >> n;
    process_input(n);
    return 0;
}
