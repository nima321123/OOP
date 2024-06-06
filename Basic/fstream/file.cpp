#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ofstream outFile;
    outFile.open("myFile.txt", ofstream::app);
    if (outFile.fail()){
        cout << "Error opening file." << endl;
        return 1;
    }

    outFile << "Beo Beo babe" << endl;
    double x = 5.2;
    int y = 3;
    string z = "abc";

    outFile << x << endl;
    outFile << y << endl;
    outFile << z << endl;
    outFile.close();
}