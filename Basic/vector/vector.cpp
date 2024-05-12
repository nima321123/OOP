// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Vector{
    private:
        int x;
        int y;
    public:
        Vector() {}
        Vector(int x,int y){
            this->x=x;
            this->y=y;
        }
        Vector operator+(const Vector &other){
            Vector result (this->x+other.x,this->y+other.y);
            return result;
        }
        Vector operator-(const Vector &other){
            Vector result (this->x-other.x,this->y-other.y);
            return result;
        }
        void describe (){
            cout<<"Vector ("<<this->x<<", "<<this->y<<") "<<endl;
        }
}; 

template <class T> class Data{
    private:
        T value1;
        T value2;
    public:
        Data (T value1, T value2){
            this->value1=value1;
            this->value2=value2; 
        }
        T sum(){
            return value1+value2;
        }
};
int main() {
    Vector v1(4, 8);
    Vector v2(1, 2);
    Data<Vector> sumVector(v1,v2);
    Vector v3=sumVector.sum();
    v3.describe();
    
    return 0;
}