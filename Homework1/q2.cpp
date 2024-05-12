#include <iostream>
using namespace std;

class Beverage{
    private:
        float price;
        float topping_price;
        float condiment_price;
    public:
        // default constructor
        Beverage(){
            price = 0;
            topping_price = 0;
            condiment_price = 0;
        }

        // constructor with parameters
        Beverage(float price, float topping_price, float condiment_price){
            this->price = price;
            this->topping_price = topping_price;
            this->condiment_price = condiment_price;
        }

        // copy constructor
        Beverage(const Beverage& other){
            this->price = other.price;
            this->topping_price = other.topping_price;
            this->condiment_price = other.condiment_price;
        }

        // overload the plus operator (+)
        Beverage operator+(Beverage& other){
            Beverage result;
            result.price = this->price + other.price;
            result.topping_price = this->topping_price + other.topping_price;
            result.condiment_price = this->condiment_price + other.condiment_price;
            return result;
        }

        // overload the comparison operator (==)
        bool operator==(Beverage& other){
            return (this->price == other.price
                 && this->topping_price == other.topping_price
                 && this->condiment_price == other.condiment_price);
        }
        void describe(){
            cout << "price: " << price << " ";
            cout << "topping price: " << topping_price << " ";
            cout << "condiment price: " << condiment_price << endl;
        }
};

int main(){
    // create beverage b0 with default constructor
    Beverage b0;
    b0.describe();

    /* create beverage b1 with price = 10.5
       topping_price = 2.3 and condiment price = 1.2*/
    Beverage b1(10.5, 2.3, 1.2);
    b1.describe();

    /* create beverage b2 with price = 15
       topping_price = 2.2 and condiment price = 0.5
    */
    Beverage b2(15, 2.2, 0.5);
    b2.describe();

    // create Beverage b3 using copy constructor
    // copy b1 into b3
    Beverage b3(b1);
    b3.describe();

    // overload plus operator (+)
    b3 = b1 + b2;   
    b3.describe();

    // overload the comparison operator (==)
    // Is b3 == b1?
    cout << "Is b3 = b1? " << (b3==b1) << endl;

    // assign b1 to b3
    // Is b3 == b1?
    b3 = b1;
    b3.describe();
    cout << "Is b3 = b1? " << (b3==b1) << endl;
    return 0;
}