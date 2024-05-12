#include <iostream>
using namespace std;

class baseClass{
    public:
        virtual void Hello(){
            cout << "Hello from base class!" << endl;
        }
};

class derivedClass : public baseClass{
    public:
        void Hello(){
            cout << "Hello from derived class!" << endl;
        }
};

int main(){
    baseClass* obj = new derivedClass;
    obj->Hello();
    delete obj;
}