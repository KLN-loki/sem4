// b) Write a Program to Demonstrate the Catching of All Exceptions

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
                cout << "number is positive : " << n << endl;
            }
            catch(...){
                cerr << "Exception number is negative" << endl;
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