#include <iostream>
using namespace std;

/* Write a program that defines an object of type double called mydouble. Define an object 
of reference type called myreference and initialize it with mydouble. Change the value of 
myreference. Print the object value using both the reference and the original variable. 
Change the value of mydouble. Print the value of both objects*/

int main(){
    double mydouble = 5.3;
    double& myreference = mydouble;

    myreference = 7.8;
    cout << "mydouble = " << mydouble << endl;
    cout << "myreference = " << myreference << endl;

    mydouble = 9.3;
    cout << "mydouble = " << mydouble << endl;
    cout << "myreference = " << myreference << endl;

    return 0;
}