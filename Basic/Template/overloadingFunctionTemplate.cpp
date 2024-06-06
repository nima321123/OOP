
#include <iostream>
using namespace std;



// overloading function template
template <typename T>
T sum(T a, T b){
    return a + b;
}

template <typename T>
T sum(T a, T b, T c){
    return a + b + c;
}
int main()
{
    cout << sum<double>(20.3, 20.6) << endl;
    cout << sum<double>(3.5, 2.0, 37.9) << endl;
    cout << sum<string>("hello ", "my ", "babe") << endl;
    return 0;
}
