#include <iostream>
using namespace std;

class Manufacturer{
    private:
        int id;
        string location;
    public: 
        Manufacturer(int id, string location){
            this->id = id;
            this->location = location ;
        }
        void describe(){
            cout << "id: " << this->id << endl;
            cout << "location: " << this->location << endl;
        }
};

class Device{
    private: 
        string name;
        double price;
        Manufacturer* manufacturer;
    public:
        Device(string name, double price, int id, string location){
            this->name = name;
            this->price = price;
            manufacturer = new Manufacturer(id, location);
        }
        void describe(){
            cout << "name: " << name << endl;
            cout << "price: " << price << endl;
            manufacturer->describe();
        }
};

int main(){
    Device mouse("mouse", 2.5, 9725, "Vietnam");
    mouse.describe();
    return 0;
}