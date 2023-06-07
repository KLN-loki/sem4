// 11. Accept two stacks as input from the user and perform operations on it using stack class
// available in Standard Template Library (STL).

#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack <int> s1, s2;
    int n1, n2;
    cout << "Enter stack sizes 1 & 2 : ";
    cin >> n1 >> n2;
    cout << "Enter stack1 elements : ";
    for(int i = 0; i < n1; i++){
        int temp;
        cin >> temp;
        s1.push(temp);
    }
    cout << "Enter stack2 elements : ";
    for(int i = 0; i < n2; i++){
        int temp;
        cin >> temp;
        s2.push(temp);
    }
    int total = 0;
    while(!s1.empty()){
        total += s1.top();
        s1.pop();
    }
    while(!s2.empty()){
        total += s2.top();
        s2.pop();
    }
    cout << "Total : " << total << endl;
    return 0;
}