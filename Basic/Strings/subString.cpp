#include<iostream>
#include<string>
using namespace std;

/*Write a program that creates two substrings from the main string. The main string is 
made up of first and last names and is equal to “John Doe.” The first substring is the first 
name. The second substring is the last name. Print the main string and two substrings 
afterward.*/

int main(){
    string full_name = "John Doe";

    //source_string.substr(starting_pos, len_substr)
    string first_name = full_name.substr(0, 4);
    string last_name = full_name.substr(5, 3);

    cout << "First name: " << first_name << endl;
    cout << "Last name: " << last_name << endl;

    return 0;
}