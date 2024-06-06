#include <iostream>
using namespace std;

class Date{
    private:
        int day;
        int month;
        int year;
    public:
        Date(int d, int m, int y): day(d), month(m), year(y) {}
        void printDate(){
            cout << day << "/" << month << "/" << year << endl;
        }
        ~Date(){
            cout << "Date destructor called." << endl;
        }
};  

class Engine{
    private:
        string origin;
        // composition
        Date productionDate;
    public:
        Engine(string origin, int d, int m, int y):productionDate(d, m, y), origin(origin){}
        void describeEngine(){
            cout << "Origin: " << origin << endl;
            productionDate.printDate(); // delegation
        }
        ~Engine(){
            cout << "Engine destructor called." << endl;
        }

};

class Car{
    private:
        string brand;
        Engine engine; // composition
    public:
        Car(string brand, Engine engine):engine(engine), brand(brand){}
        void describeCar(){
            cout << "Brand: " << brand << endl;
            engine.describeEngine();
        }
        ~Car(){
            cout << "Car destructor called." << endl;
        }
};

int main(){
    Engine engine("Malaysia", 3, 1, 2022);
    Car car("Honda", engine);
    car.describeCar();
}