#include <iostream>
using namespace std;

template <class T> class Data{
    private:
        T value1;
        T value2;
    public:
        Data(T param1, T param2):value1(param1), value2(param2) {}
        T sum(){
            return value1 + value2;
        }

        T subtract(){
            return value1 - value2;
        }
        void describe(){
            cout << "Value of the first parameter: " << value1 << endl;
            cout << "value of the second parameter: " << value2 << endl;
        }
};

class Square{
    Square(){} // default constructor
    private:
        int side;
    public:
        Square(int side): side(side) {}
        Square operator+(Square& other){
            Square result(this->side + other.side);
            return result;
        }
        Square operator-(Square& other){
            Square result(this->side - other.side);
            return result;
        }
        void describe(){
            cout << "Side: " << this->side << endl;
        }
};

class Vector{
    private:
        int x;
        int y;
    public:
        Vector(){} // default constructor
        Vector(int x, int y): x(x), y(y){}
        Vector operator+(Vector& other){
            Vector result(this->x + other.x, this->y + other.y);
            return result;
        }
        Vector operator-(Vector& other){
            Vector result(this->x - other.x, this->y - other.y);
            return result;
        }
        void describe(){
            cout << "x = " << x << endl;
            cout << "y = " << y << endl;
        }
};


int main(){
    // Class Data with template
    /*Data<int> data1(3, 9);
    Data<double> data2(20.5, 8.75);

    data1.describe();
    cout << "Sum: " << data1.sum() << endl;
    data2.describe();
    cout << "Subtraction: " << data2.subtract() << endl;*/

    // Square class
    Square square1(5);
    Square square2(3);
    /*Square square3(square1+square2);
    square3.describe();

    Square square4(square1-square2);
    square4.describe();*/

    // Square using Data class
    Data<Square> squareData(square1, square2);
    Square sumSquare = squareData.sum();
    sumSquare.describe();

    // Vector class
    Vector vector1(3, 4);
    Vector vector2(6, 2);

    /*Vector vector3 = vector1 + vector2;
    vector3.describe();
    Vector vector4 = vector1 - vector2;
    vector4.describe();*/
    Data<Vector> vectorData(vector1, vector2);
    Vector vector3 = vectorData.sum();
    vector3.describe();
}

