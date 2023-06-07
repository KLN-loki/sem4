// b) Write a program that demonstrates virtual, static functions

#include <iostream>
using namespace std;

class base{
    public :
        virtual void virtualFun(){
            cout << "Virtual Function base" << endl;
        }
        static void staticFun(){
            cout << "Static Function base" << endl;
        }
};

class derived : public base{
    public :
        void virtualFun(){
            cout << "virtual Function derived" << endl;
        }
        static void staticFun(){
            cout << "Static Function derived" << endl;
        }
};

int main(){
    base *b;
    derived d;
    b = &d;
    base :: staticFun();
    b -> virtualFun();
    derived :: staticFun();
    d.virtualFun();
    return 0;
}