// b)Write a program to illustrate default constructor, parameterized constructor and copy constructor,
// destructors for a class

#include <iostream>
using namespace std;


class Rectangle{
    private :
        int width, height;
    public :
        Rectangle(){
            width = 0;
            height = 0;
        }
        Rectangle(int w, int h){
            width = w;;
            height = h;
        }
        int area(){
            return width*height;
        }
        int perimeter(){
            return 2*(width+height);
        }
        ~Rectangle(){
            cout << "Destructor executed." << endl;
        }
};

int main(){
    int w, h, area, perimeter;
    cout << "Enter width and height : ";
    cin >> w >> h;
    Rectangle obj1;
    Rectangle obj2(w, h);
    Rectangle obj3(obj2);
    cout << "Default constructor >> " << endl;
    area = obj1.area();
    perimeter = obj1.perimeter();
    cout << "Area = " << area << endl << "Perimeter = " << perimeter << endl;
    cout << "Parameterized constructor >> " << endl;
    area = obj2.area();
    perimeter = obj2.perimeter();
    cout << "Area = " << area << endl << "Perimeter = " << perimeter << endl;
    cout << "Copy constructor >> " << endl;
    area = obj3.area();
    perimeter = obj3.perimeter();
    cout << "Area = " << area << endl << "Perimeter = " << perimeter << endl;
    cout << "Destructors executing...." << endl;
    return 0;
}