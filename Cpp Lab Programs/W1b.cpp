// b) Write a program which uses function to swap two integers and two float numbers by using
// reference variable

#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void swap(float &a, float &b){
    float temp = a;
    a = b;
    b = temp;
}

int main(){
    int a, b;
    float c, d;
    cout << "Enter integers a and b : ";
    cin >> a >> b;
    cout << "Before swaping : " << endl;
    cout << "a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "After swaping : " << endl;
    cout << "a = " << a << ", b = " << b << endl;
    cout << "Enter floating point numbers c and d : ";
    cin >> c >> d;
    cout << "Before swaping : " << endl;
    cout << "c = " << c << ", d = " << d << endl;
    swap(c, d);
    cout << "After swaping : " << endl;
    cout << "c = " << c << ", d = " << d << endl;
}