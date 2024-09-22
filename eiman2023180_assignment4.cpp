#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

// 1. Function to divide two numbers, demonstrating std::invalid_argument
double Divide(double numerator, double denominator) {
    if (denominator == 0) {
        throw invalid_argument("Denominator cannot be zero!");
    }
    return numerator / denominator;
}

// 2. Function to access an element in an array, demonstrating std::out_of_range
int GetElement(int data[], int size, int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index is out of range for this array!");
    }
    return data[index];
}

// 3. Function demonstrating std::bad_alloc
void AllocateMemory(int size) {
    try {
        int* arr = new int[size];
        std::cout << "Memory allocated successfully!\n";
        delete[] arr;
    } catch (const std::bad_alloc& e) {
        cerr << "Memory allocation failed: " << e.what() << '\n';
    }
}

// 4. Function performing integer division, demonstrating std::overflow_error
int DivideLargeNumbers(int a, int b) {
    if (a > INT_MAX / b || a < INT_MIN / b) {
        throw overflow_error("Integer division overflow");
    }
    return a / b;
}

// 5. Function checking for array size, demonstrating std::length_error
void CheckArraySize(int data[], int size) {
    if (size > 100) {
        throw length_error("Array size exceeds limit");
    }
}

// 6/7. Function demonstrating attempt to write to a read-only array(logic_error and runtime_error)
void WriteToReadOnlyArray(const int data[], int size, int index, int value) {
    if (!data) {
        throw runtime_error("Array pointer is null");
    }

    throw logic_error("Attempt to write to a read-only array"); // Example of custom logic error
}

// 8. Function demonstrating std::range_error
void rangeErrorFunction(int value) {
    if (value < 0 || value > 100) {
        throw range_error("Value is out of range (0-100)");
    }
    cout << "Value " << value << " is within the valid range." << std::endl;
}

// 9. Function demonstrating std::underflow_error
void underflowErrorFunction(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; ++i) {
        result /= base;
        if (result == 0.0) {
            throw underflow_error("Result underflowed to zero");
        }
    }
    std::cout << "Result after exponentiation: " << result << std::endl;
}

// 10. Function demonstrating std::domain_error
void domainErrorFunction(int radius) {
    if (radius < 0) {
        throw domain_error("Radius cannot be negative");
    }
    double area = 3.14 * radius * radius;
    cout << "Area of the circle: " << area << endl;
}

int main() {
    try {
        // Test Divide function
        double result = Divide(10, 0);
    } catch (const std::invalid_argument& e) {
        cerr << "Invalid Argument: " << e.what() << endl;
    }

    try {
        // Test GetElement function
        int data[] = {1, 2, 3};
        int element = GetElement(data, sizeof(data) / sizeof(data[0]), 5);
    } catch (const std::out_of_range& e) {
        cerr << "Out of Range: " << e.what() << endl;
    }

    try {
        // Test AllocateMemory function
        AllocateMemory(99999999999999); // Large allocation might fail
    } catch (const std::bad_alloc& e) {
        cerr << "Bad Alloc: " << e.what() << endl;
    }

    try {
        // Test DivideLargeNumbers function
        int result = DivideLargeNumbers(INT_MAX, 2);
    } catch (const std::overflow_error& e) {
        cerr << "Overflow Error: " << e.what() << endl;
    }

    try {
        // Test CheckArraySize function
        int data[200];
        CheckArraySize(data, sizeof(data) / sizeof(data[0]));
    } catch (const std::length_error& e) {
        cerr << "Length Error: " << e.what() << endl;
    }

    try {
        // Test WriteToReadOnlyArray function
        const int data[] = {1, 2, 3};
        WriteToReadOnlyArray(data, sizeof(data) / sizeof(data[0]), 0, 10);
    } catch (const std::logic_error& e) {
        cerr << "Logic Error: " << e.what() << endl;
    } catch (const std::runtime_error& e) {
        cerr << "Runtime Error: " << e.what() << endl;
    }

    try {
        // Test rangeErrorFunction
        rangeErrorFunction(50); // No exception
        rangeErrorFunction(150); // Throws std::range_error
    } catch (const std::range_error& e) {
        cerr << "Range Error: " << e.what() << endl;
    }

    try {
        // Test underflowErrorFunction
        underflowErrorFunction(2.0, 1000); // May throw std::underflow_error
        underflowErrorFunction(0.5, 1000); // No exception
    } catch (const std::underflow_error& e) {
        cerr << "Underflow Error: " << e.what() << endl;
    }

    try {
        // Test domainErrorFunction
        domainErrorFunction(5); // No exception
        domainErrorFunction(-5); // Throws std::domain_error
    } catch (const std::domain_error& e) {
        cerr << "Domain Error: " << e.what() << endl;
    }

    return 0;
}
