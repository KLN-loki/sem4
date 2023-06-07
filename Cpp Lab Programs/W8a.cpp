// 8. Write a Program to demonstrates user defined exceptions

#include <iostream>
#include <exception>
using namespace std;

class MyException : public exception {
    public:
        const char* what() const throw() {
            return "My Exception occurred!";
        }
};

int main() {
    try {
        int num1, num2;
        cout << "Enter two integers: ";
        cin >> num1 >> num2;

        if (num2 == 0) {
            throw MyException();
        }

        int result = num1 / num2;
        cout << "Result: " << result << endl;
    }
    catch (MyException& e) {
        cout << "Error: " << e.what() << endl;
    }
    catch (...) {
        cout << "An exception occurred." << endl;
    }

    return 0;
}
