// 6 a) Write a program which uses the concept of pass and return objects to functions.

#include <iostream>
using namespace std;

class area{
    private:
        int ln, br;
    public :
        area(int l = 0, int b = 0){
            ln = l;
            br = b;
        }
        void FindArea(){
            cout << "area = " << ln*br << endl;
        }
        area add(area obj){
            area res;
            res.ln = ln + obj.ln;
            res.br = br + obj.br;
            return res;
        }
};

int main(){
    area obj1(4, 5), obj2(2, 3);
    area obj3 = obj1.add(obj2);
    obj3.FindArea();
    return 0;
}