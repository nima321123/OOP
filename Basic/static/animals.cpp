#include <iostream>
using namespace std;

class Animal{
    private:
        string name;
        static int number;
    public:
        
        Animal(string name){
            this->name = name;
            number ++;
        }
        virtual void makeSound(){
            cout << "animal sound ..." << endl;
        }
        virtual void describe(){
            cout << "Name: " << name << endl;
        }
        static int getTotal(){
            return Animal::number;
        }
};

int Animal::number = 0;

class Cat: public Animal{
    private:
        string color;
    public:
        Cat(string name, string color):Animal(name),color(color){}
        void makeSound(){
            cout << "Meow meow..."<< endl;
        }
        void describe(){
            Animal::describe();
            cout << "Color: " << this->color << endl;
        }

};

class Dog: public Animal{
    private:
        string color;
    public:
        Dog(string name, string color):Animal(name){
            this->color = color;
        }
        void makeSound(){
            cout << "Gau gau..." << endl;
        }
        void describe(){
            Animal::describe();
            cout << "Color: " << this->color << endl;
        }
};

int main(){
    Animal *dog = new Dog("Alaska", "gray");
    Animal *cat = new Cat("Calico", "yellow");

    dog->makeSound();
    dog->describe();
    cat->makeSound();
    cat->describe();
    cout << Animal::getTotal() << endl;
    cout << "************" << endl;
    Dog dog2("Phu Quoc", "black");
    cout << Animal::getTotal() << endl;
    dog2.describe();
    dog2.makeSound();
    cout << dog2.getTotal() << endl;
}