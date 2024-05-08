#include <iostream>
using namespace std;

template <typename T>
void myfunc(T param){
    cout << "The value of the parameter is: " << param << endl;
}

int main(){
    myfunc<int>(34);
    myfunc<double>(23.75);
    myfunc<char>('Y');
}