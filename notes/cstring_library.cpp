#include <iostream>
#include <cstring> // important or #include<string.h>
using namespace std;

int main()
{
    char greet[16] = "Welcome to VGU!";
    string greet1 = "Welcome to VGU!";
    char name[] = "OOP Course";
    char a_copy[11];
    strcpy(name, a_copy);
    
    cout << greet << endl;
    cout << a_copy << endl;
    cout << name << endl;
    cout << greet1.size() << endl; // use string.size() for string
    cout << strlen(greet); // use strlen(my_string) for char array
    //strlen, strcpy, strcat... come with the cstring library

    return 0;
}