#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char greet[16] = "Welcome to VGU!";
    char name[] = "OOP Course";
    char a_copy[11];
    char con_cat[] = "2024";
    
    strcpy(name, a_copy); // strcpy(destination, source)
    strcat(a_copy, con_cat); // strcat(destination, source)
    
    cout << greet << endl;
    cout << name << endl;
    cout << a_copy << endl;

    return 0;
}