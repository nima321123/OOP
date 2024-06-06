#include <iostream>
using namespace std;

class IceCream {
    float icePrice;
    float toppingPrice;
    float flavorPrice;

public:
    // Default constructor
    IceCream() : icePrice(0), toppingPrice(0), flavorPrice(0) {}

    // Constructor with parameters
    IceCream(float icePrice, float toppingPrice, float flavorPrice) : icePrice(icePrice), toppingPrice(toppingPrice), flavorPrice(flavorPrice) {}

    // Copy constructor
    IceCream(const IceCream& other) : icePrice(other.icePrice), toppingPrice(other.toppingPrice), flavorPrice(other.flavorPrice) {}

    // Overloaded subtraction operator
    IceCream operator-(const IceCream& other) const {
        return IceCream(icePrice - other.icePrice, toppingPrice - other.toppingPrice, flavorPrice - other.flavorPrice);
    }

    // Overloaded less than or equal operator
    bool operator<=(const IceCream& other) const {
        return icePrice <= other.icePrice && toppingPrice <= other.toppingPrice && flavorPrice <= other.flavorPrice;
    }

    // Describe method
    void describe() const {
        cout << "Ice Price: " << icePrice << ", Topping Price: " << toppingPrice << ", Flavor Price: " << flavorPrice << endl;
    }
};

int main(){
    IceCream ic0;
    ic0.describe();

    IceCream ic1(10.5, 2.3, 1.2);
    ic1.describe();

    IceCream ic2(15, 5.2, 7.5);
    ic2.describe();

    IceCream ic3(ic1);
    ic3.describe();

    ic3 = ic2 - ic1;
    ic3.describe();

    ic3 <= ic1;
    ic3.describe();
    cout << "Is ic3 <= ic1? " << (ic3 <= ic1) << endl;
    return 0;
}