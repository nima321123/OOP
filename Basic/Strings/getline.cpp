#include <iostream>
#include <string>
using namespace std;

/*Write a program that accepts the first and the last name from the standard input using 
the std::getline function. Store the input in a single string called fullname. Print out 
the string*/

int main(){
    string full_name;
    cout << "Enter your first and last name: ";
    getline(cin, full_name);

    cout << "Full name: " << full_name;

    return 0;
}