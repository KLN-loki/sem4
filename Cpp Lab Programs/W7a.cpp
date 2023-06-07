// 7 a) Write a program that handles Exceptions. Use a Try Block to Throw it and a Catch Block to
// Handle it Properly.

#include <iostream>
using namespace std;

class a{
    private :
        int n;
    public :
        a(int num = 0){
            n = num;
        }
        void condition(){
            try{
                if(n < 0){
                    throw n;
                }
                else {
                    cout << "number is positive : " << n << endl;
                }
            }
            catch(const int e){
                cerr << "Exception number is negative : " << e << endl;
            }
        }
};

int main(){
    int num;
    cout << "Enter n : ";
    cin >> num;
    a obj(num);
    obj.condition();
    return 0;
}