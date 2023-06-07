// b) Create multiple objects for the class and observe the order in which constructors and destructors
// are called.

#include <iostream>
using namespace std;

class cls{
    private:
        int n;
    public :
        cls(int a){
            n = a;
            cout << "Constructor " << n << endl;
        }
        ~cls(){
            cout << "Destructor " << n << endl;
        }
};

int main(){
    cls obj1(1);
    cls obj2(2);
    cls obj3(3);
    return 0;
}