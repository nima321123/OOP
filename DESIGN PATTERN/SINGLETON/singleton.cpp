#include <iostream>
using namespace std;

class Singleton{
    protected:
        Singleton(){}
    public:
        int data;
        static Singleton& get_instance(){
            
            static Singleton instance;
            return instance;
        }
        // Singletons should not be cloneable
        Singleton(const Singleton&) = delete; 
        // Singletons should not be assignable
        Singleton operator=(const Singleton &) = delete;
};

int main(){
    Singleton &singleton1 = Singleton::get_instance();
    singleton1.data = 20;

    Singleton &singleton2 = Singleton::get_instance();

    Singleton::get_instance().data = 50;
    cout << "data: " << Singleton::get_instance().data << endl;
    cout << "singleton1.data = " << singleton1.data << endl;
    cout << "singleton2.data = " << singleton2.data << endl;
    
    cout << "address1: " << &singleton1 << endl;
    cout << "address2: " << &singleton2 << endl;
    
    return 0;
}