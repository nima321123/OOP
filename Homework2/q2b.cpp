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
    Date* publicationDate;

public:
    Book(string name, string author, Date* publicationDate): name(name), author(author), publicationDate(publicationDate){}

    void describe() {
        cout << "Book Name: " << name << " - ";
        cout << "Author: " << author << endl;
        publicationDate->describe();
    }
};
int main() {
    Date date(27, 6, 2022);
    Book book("C++", "Peter", &date);
    book.describe();

    return 0;
}
