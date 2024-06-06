#include <iostream>
using namespace std;

class Date {
    int day;
    int month;
    int year;

public:
    Date(int day, int month, int year) : day(day), month(month), year(year) {}

    void describe() {
        cout << "Publication Date: " << day << "/" << month << "/" << year << endl;
    }
};

class Book {
    string name;
    string author;
    Date publicationDate;

public:
    Book(string name, string author, int day, int month, int year):publicationDate(day, month, year){
        this->name = name;
        this->author = author;
    }

    void describe() {
        cout << "Book Name: " << name << " - ";
        cout << "Author: " << author << endl;
        publicationDate.describe();
    }
};
int main() {
    Book book("C++", "Peter", 27, 6, 2022);
    book.describe();

    return 0;
}
