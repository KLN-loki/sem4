// b) Write a program to create an array of objects.

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
    area a[3] = {area(4, 5), area(2, 3)};
    a[2] = a[0].add(a[1]);
    a[2].FindArea();
    return 0;
}