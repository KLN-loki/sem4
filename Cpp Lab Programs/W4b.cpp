// b) Write a program that demonstrates function overloading, operator overloading, overriding

#include <iostream>
using namespace std;

class base{
    public :
        int num;
        base(){
            
        }
        base(int x){
            num = x;
        }
        void print(int num1){
            cout << "Integer Function : " << num1 << endl;
        }
        void print(double num2){
            cout << "Double Function : " << num2 << endl;
        }
        base operator+(const base& obj) {
            base res(0);
            res.num = num + obj.num;
            return res;
        }
};

class derived : public base{
    public :
        derived(){

        }
        void print(int num){
            cout << "Derived class print function " << num << endl;
        }
};

int main(){
    base bobj1(1), bobj2(2), bobj3(0), *bp;
    bobj1.print(2);
    bobj2.print(35.67);
    bobj3 = bobj1+bobj2;
    cout << "By operator Overloading sum : " << bobj3.num << endl; 
    derived dobj;
    dobj.print(5);
    return 0;
}