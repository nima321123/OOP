#include <iostream>
#include <string>
using namespace std;

class Square{
    private:
        int side;
    public:
        Square() {}
        Square(int side): side(side) {}
        
        Square operator+(const Square& other){
            Square result(this->side + other.side);
            return result;
        }
        void describe(){
            cout << "Side: " << side << endl;
        }
};

template <class T> 
class Data{
    private:
        T value1;
        T value2;
    public:
        Data(T value1, T value2){
            this->value1 = value1;
            this->value2 = value2;
        }
        T sum(){
            return value1 + value2;
        }
};

int main(){
    Data<int> intData(5, 6);
    cout << "sum 1: " << intData.sum() << endl;
    
    Data<double> doubleData(1.0, 3.0);
    cout << "sum 2: " << doubleData.sum() << endl;
    
    string s1 = "C++ ";
    string s2 = "Programming";
    Data<string> stringData(s1, s2);
    cout << "sum 3: " << stringData.sum() << endl;
    
    Square square1(5);
    Square square2(10);
    Data<Square> SquareData(square1, square2);
    Square sumSquare = SquareData.sum();
    sumSquare.describe();
}
