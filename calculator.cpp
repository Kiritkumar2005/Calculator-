#include <iostream>
using namespace std;

// Define a structure for an operation
struct Operation {
    string name;
    void (*perform)();  // Function pointer to perform the operation
};

// Function prototypes
void addition();
void subtraction();
void multiplication();
void division();
void factorial();
void power();
void squareRoot();

// Global variables for inputs and results
double num1, num2, result;
int exponent;

int main() {
    // Array of operations
    Operation operations[] = {
        {"Addition", addition},
        {"Subtraction", subtraction},
        {"Multiplication", multiplication},
        {"Division", division},
        {"Factorial", factorial},
        {"Power (x^y)", power},
        {"Square Root", squareRoot}
    };

    const int numOperations = sizeof(operations) / sizeof(operations[0]);
    int choice;

    do {
        // Display menu
        cout << "\nSimple C++ Calculator" << endl;
        for (int i = 0; i < numOperations; ++i) {
            cout << i + 1 << ". " << operations[i].name << endl;
        }
        cout << numOperations + 1 << ". Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Perform the chosen operation
        if (choice >= 1 && choice <= numOperations) {
            operations[choice - 1].perform();
        } else if (choice != numOperations + 1) {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != numOperations + 1);

    cout << "Exiting program." << endl;
    return 0;
}

// Operation functions
void addition() {
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    result = num1 + num2;
    cout << "Result: " << result << endl;
}

void subtraction() {
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    result = num1 - num2;
    cout << "Result: " << result << endl;
}

void multiplication() {
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    result = num1 * num2;
    cout << "Result: " << result << endl;
}

void division() {
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    if (num2 == 0) {
        cout << "Division by zero is not allowed." << endl;
    } else {
        result = num1 / num2;
        cout << "Result: " << result << endl;
    }
}

void factorial() {
    cout << "Enter a number: ";
    cin >> num1;
    if (num1 < 0 || floor(num1) != num1) {
        cout << "Factorial is not defined for negative or non-integer numbers." << endl;
    } else {
        long long fact = 1;
        for (int i = 1; i <= num1; ++i) {
            fact *= i;
        }
        cout << "Factorial of " << (int)num1 << " is " << fact << endl;
    }
}

void power() {
    cout << "Enter base number: ";
    cin >> num1;
    cout << "Enter exponent: ";
    cin >> exponent;

    result = 1;
    for (int i = 0; i < abs(exponent); ++i) {
        result *= num1;
    }

    if (exponent < 0) {
        result = 1 / result;
    }

    cout << "Result: " << result << endl;
}

void squareRoot() {
    cout << "Enter a number: ";
    cin >> num1;
    if (num1 < 0) {
        cout << "Square root of a negative number is not defined in real numbers." << endl;
    } else {
        double temp, sqrtResult;
        sqrtResult = num1 / 2;  // Initial guess for the square root
        do {
            temp = sqrtResult;
            sqrtResult = (temp + (num1 / temp)) / 2;
        } while (temp != sqrtResult);  // Loop until precision is achieved
        cout << "Square root: " << sqrtResult << endl;
    }
}