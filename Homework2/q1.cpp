#include <iostream>
#include <vector>
using namespace std;

class Media{
    public:
        virtual void describe() = 0; // Pure virtual function
};

class Book:public Media{
    private:
        string name;
        double price;
    public:
        Book(string name, double price):name(name), price(price){}
        void describe(){
            cout << "name: " << name << "; price: " << price << endl; 
        }
};

class CD: public Media{
    private:
        string ID;
        double price;
    public:
        CD(string ID, double price):ID(ID), price(price){}
        void describe(){
            cout << "ID: " << ID << "; price: " << price << endl; 
        }
};

class Library{
    private:
        string name;
        vector<Media*> mediaList;
    public:
        Library(string name):name(name){}
        void addMedia(Media* media){
            mediaList.push_back(media);
        }
        void describe(){
            cout << "Lib Name: " << name << endl;
            for (Media* media : mediaList){
                media->describe();
            }
        }
};

int main(){
    Book book1("C++", 20.0);
    book1.describe();

    CD cd1("12345", 5.52);
    cd1.describe();

    cout << "Library Content \n";

    Book book2("C#", 21.0);
    Library library("Lib1");
    
    library.addMedia(&book1);
    library.addMedia(&book2);
    library.addMedia(&cd1);
    library.describe();

    return 0;
}   
