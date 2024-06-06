#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream inFile;
    inFile.open("myFile.txt");
    if (inFile.fail()){
        cout << "Error opening file." << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)){
        cout << line << endl;
    }

    inFile.close();
}