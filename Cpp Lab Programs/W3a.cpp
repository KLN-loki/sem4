// 3. a) Write a program that illustrates the following forms of inheritances
// Single Multiple Multilevel Hierarchical

#include <iostream>
using namespace std;

class base{
    public :
        int baseN = 10;
        void baseFun(){
            cout << baseN << endl;
        }
};

class single : public base{
    public :
        int singleN = 20;
        void singleFun(){
            cout << singleN << " " << baseN << endl;
        }
};

class multiLevel : public single{
    public :
        int multiN = 30;
        void multiFun(){
            cout << multiN << " " << singleN << " " << baseN << endl;
        }
};

class heirarichal : public single{
    public :
        int heirarN = 40;
        void heirarFun(){
            cout << heirarN << " " << singleN << " " << baseN << endl;
        }
};

class multiple : public heirarichal, public multiLevel{
    public :
        int multipleN = 50;
        void multipleFun(){
            cout << multipleN << " " << heirarN << " " << multiN << endl;
        }
};

int main(){
    base baseObj;
    baseObj.baseFun();
    single singleObj;
    singleObj.singleFun();
    singleObj.baseFun();
    multiLevel multiObj;
    multiObj.multiFun();
    multiObj.singleFun();
    multiObj.baseFun();
    heirarichal heirarObj;
    heirarObj.heirarFun();
    heirarObj.singleFun();
    heirarObj.baseFun();
    multiple multipleObj;
    multipleObj.multipleFun();
    multipleObj.multiFun();
    multipleObj.heirarFun();
    return 0;
}