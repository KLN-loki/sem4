// 4 a) Write a program to use pointers for both base and derived classes and call the member
// functions.

#include <iostream>
using namespace std;

class base{
    public :
        int baseN = 10;
        void baseFun(){
            cout << "Base Function : " << baseN << endl;
        }
};

class derived : public base{
    public :
        int derivedN = 20;
        void derivedFun(){
            cout << "Derived Function : " << derivedN << endl;
        }
};

int main(){
    base *bp;
    derived dobj;
    bp = &dobj;
    bp -> baseFun();
    dobj.derivedFun();
    return 0;
}