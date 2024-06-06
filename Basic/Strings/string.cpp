#include <iostream>
//#include <string>
#include <string.h>
using namespace std;

int main(){
    string test1 = "abcdef";
    cout << test1 << endl;
    cout << test1.size() << endl;
    cout << test1.length() << endl;
    cout << test1[1] << endl;
    cout << test1.at(3) << endl;
    test1[2] = 'C';
    cout << test1 << endl;
    test1 += "meow";
    test1.append("MEOW");
    test1.clear();
    cout << test1.empty() << endl;
    string test2 = to_string(-0.2348);
    cout << test2 << endl;
    string name;
    getline(cin, name);
    cout << name;
    strcpy(test2, test1);
    cout << test2 << endl;
}