// 1. a) Write a program to generate the following sequence
// 1
// 1 2
// 1 2 3
// 1 2 3 4

#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter n : ";
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout << j+1 << " ";
        }
        cout << endl;
    }
    return 0;
}