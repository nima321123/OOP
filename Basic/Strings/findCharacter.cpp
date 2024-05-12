#include <iostream>
using namespace std;

/*Write a program that defines the main string with a value of “Hello C++ World.” and 
checks if a single character ‘C’ is found in the main string.*/

int main(){
    string sample = "Hello C++ World.";
    string target = "lW";
    int pos = sample.find(target);

    if (0 <= pos && pos <= sample.size()){
        cout << "Character found at position " << pos << endl;
    }
    else cout << "Character not found." << endl;

    return 0;
}

/*n C++, the std::string::find function returns the position of the first occurrence of the 
specified substring or character within the string. However, if the substring or character 
is not found, it returns a special value called std::string::npos.*/