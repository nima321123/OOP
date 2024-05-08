#include <iostream>
using namespace std;

class Product{
    private:
        float price;
        float weight;
        float discount;
    public:
        // default constructor
        Product(){
            price = 0;
            weight = 0;
            discount = 0;
        }

        // constructor with parameters
        Product(float price, float weight, float discount) {
            this->price = price;
            this->weight = weight;
            this->discount = discount;
        }
        // copy constructor
        Product(const Product& other) : price(other.price), weight(other.weight), discount(other.discount) {}

        // plus operator (+) overload
        Product operator+(const Product& other){
            Product result;
            result.price = this->price + other.price;
            result.weight = this->weight + other.weight;
            result.discount = this->discount + other.discount;
            return result;
        }

        // assignment operator (=) overload
        void operator=(const Product& other){
            this->price = other.price;
            this->weight = other.weight;
            this->discount = other.discount;
        }

        // comparison operator (==) overload
        bool operator==(const Product& other) const{
            return (this->price == other.price &&
                this->weight == other.weight &&
                this->discount == other.discount);
        }

        // describe() method
        void describe(){
            cout << "Price: " << price << endl;
            cout << "Weight: " << weight << endl;
            cout << "Discount: " << discount << endl;
        }

};

int main(){
    Product product1; // default constructor invoked; price, weight, and discount initialized to zero
    Product product2(20.17, 1.5, 0.25); 
    Product product3(product2); // copy constructor invoked

    cout << "product1: " << endl; product1.describe();
    cout << "product2: " << endl; product2.describe();
    cout << "product3: " << endl; product3.describe();
    cout << "------------------" << endl;

    product2 = product1;
    if (product1 == product2) cout << "Product1 == Product2" << endl;
        else cout << "Product1 != Product2" << endl;
    if (product2 == product3) cout << "Product2 == Product3" << endl;
        else cout << "Product2 != Product3" << endl;

    cout << "product1: " << endl; product1.describe();
    cout << "product2: " << endl; product2.describe();
    cout << "product3: " << endl; product3.describe();

    

}