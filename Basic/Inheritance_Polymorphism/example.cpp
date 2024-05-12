#include <iostream>
using namespace std;

class Instrument{
    public:
        virtual void makeSound(){
            cout << "Instrument playing ...";
        }
};

class Guitar:public Instrument{
    public: 
        void makeSound(){
            cout << "Guitar playing...";
        }
};

int main(){
    Guitar* i1 = new Instrument;
    i1->makeSound();
}