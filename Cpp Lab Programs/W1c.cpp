// c) Write a program that demonstrates default arguments

#include <iostream>
using namespace std;

int sum(int a, int b, int c = 5){
    return a + b + c;
}

int main(){
    int a, b, c;
    cout << "Enter a and b : ";
    cin >> a >> b;
    int result = sum(a, b);
    cout << "Sum = " << result << " by passing only a and b having default argument c = 5" << endl;
    cout << "Enter c : ";
    cin >> c;
    result = sum(a, b, c);
    cout << "Sum = " << result << " passing a, b, c to sum function." << endl;
    return 0;
}