// 5 a) Write a program that demonstrates friend functions, inline functions

#include <iostream>
using namespace std;

class cls{
    private :
        int num;
    public :
        cls(int n){
            num = n;
        }
        friend void friendFun(cls obj);
        inline void inlineFun(){
            cout << "Inline Function : " << num << endl;
        }
};

void friendFun(cls obj){
    cout << "Friend Function : " << obj.num << endl;
}

int main(){
    int n;
    cout << "Enter n : ";
    cin >> n;
    cls obj(n);
    obj.inlineFun();
    friendFun(obj);
    return 0;
}