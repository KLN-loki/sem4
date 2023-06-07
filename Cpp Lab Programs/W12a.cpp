// 12. Write a program implementing a queue class with required operations using STL.

#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;
    cout << "Queue size: " << q.size() << endl;
    q.pop();
    cout << "Queue size after pop: " << q.size() << endl;
    return 0;
}
