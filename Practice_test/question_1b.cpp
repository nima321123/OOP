#include <iostream>
using namespace std;

class Course{
    private:
        int courseCode;
        string courseName;
    public:
        Course(int courseCode, string courseName):courseCode(courseCode), courseName(courseName){}
        void describe(){
            cout << "Course code: " << courseCode << endl;
            cout << "course name: " << courseName << endl;
        }
};
class Student{
    private:
        string name;
        int studentID;
        Course* course;
    public:
        Student(string name, int studentID, int courseCode, string courseName){
            this->name = name;
            this->studentID = studentID;
            this->course = new Course(courseCode, courseName); 
            // create a new Course object and assign it to the course pointer in the Student constructor
        }
        ~Student(){
            delete course;
        }
        void describe(){
            cout << "Name: " << name << endl;
            cout << "Student ID: " << studentID << endl;
            course->describe();
        }

};

int main(){
    Student student1("Jose Peterson", 128456, 102, "Introduction to Computer Science");
    student1.describe();
}