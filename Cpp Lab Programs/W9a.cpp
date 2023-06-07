// 9. Write a program to create a generic template for adding two integers and two float values and
// make use of the template to perform addition.

#include <iostream>
using namespace std;

template <typename t>
t add(t num1, t num2){
    return num1+num2;
}

int main(){
    int a, b;
    float c, d;
    cout << "Enter integers a & b : ";
    cin >> a >> b;
    cout << "Enter float c & d : ";
    cin >> c >> d;
    cout << "Sum of Int : " << add(a, b) << endl;
    cout << "Sum of Float : " << add(c, d) << endl;
    return 0;
}