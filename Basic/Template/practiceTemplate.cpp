#include <iostream>
using namespace std;

template<class T> class Data{
    private:
        T value1;
        T value2;
    public:
        Data(T val1, T val2): value1(val1), value2(val2){}
        T sum(){
            return value1 + value2;
        }
};

class Circle{
    private:
        int side;
    public:
        Circle():side(0){}
        Circle(int side):side(side){}
        int getSide(){
            return side;
        }
        void describe(){
            cout << "Side: " << side << endl;
        }
};

int main(){
    Data<int> intData(5, 6);
    cout << "Sum 1: " << intData.sum() << endl;

    Circle circle1(5);
    Circle circle2(2);
    Data<int> circleData(circle1.getSide(), circle2.getSide());
    int sumSide = circleData.sum();
    Circle sumCircle(sumSide);
    sumCircle.describe();
}