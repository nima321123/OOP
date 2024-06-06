#include <iostream>
using namespace std;

template <typename T>
class Data {
    T a;
    T b;

public:
    Data(T a, T b) : a(a), b(b) {}

    T sum() {
        return a + b;
    }
};

class Circle {
    double radius;

public:
    Circle(double radius) : radius(radius) {}

    double getRadius() const {
        return radius;
    }

    Circle operator+(const Circle& other) const {
        return Circle(radius + other.radius);
    }
    void describe(){
        cout << "radius: " << radius << endl;
    }
};

int main(){
    Data<int> intData(5, 6);
    cout << "sum 1: " << intData.sum() << endl;

    Circle circle1(5);
    Circle circle2(7);
    Data<Circle> circleData(circle1, circle2);
    Circle sumCircle = circleData.sum();
    sumCircle.describe();
}
