// 2. a) Write a program Illustrating Class Declarations, Definition, and Accessing Class Members.

#include <iostream>
using namespace std;

class Rectangle{
    private :
        int width, height;
    public :
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
};

int main(){
    int w, h;
    cout << "Enter width and height : ";
    cin >> w >> h;
    Rectangle obj(w, h);
    int area = obj.area();
    int perimeter = obj.perimeter();
    cout << "Area = " << area << endl << "Perimeter = " << perimeter << endl;
    return 0;
}