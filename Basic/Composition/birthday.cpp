#include <iostream>
using namespace std;

class Birthday{
    private:
        int day;
        int month;
        int year;
    public:
        Birthday(int d, int m, int y){
            day = d;
            month = m;
            year = y;
            cout << "Birthday constructor called."<< endl;
        }
        void printBirthday(){
            cout << "Their birthday is: " << day << "/" << month << "/" << year << endl;
        }
        ~Birthday(){
            cout << "Birthday destructor called." << endl;
        }
};

class Person{
    private:
        Birthday birthday;
        string name;
    public:
        Person(Birthday& bd, string name):birthday(bd){
            this->name = name;
            cout << "Person constructor called"<< endl;
        }
        void describe(){
            cout << "Name: " << name << endl;
            birthday.printBirthday();
        }
        ~Person(){
            cout << "Person destructor called." << endl;
        }
};

int main(){
    Birthday bd(3, 9, 1980);
    Person person1(bd, "Anna");
    person1.describe();
}