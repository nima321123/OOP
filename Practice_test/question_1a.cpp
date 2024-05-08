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
        Course course;
    public:
        Student(string name, int studentID, int courseCode, string courseName) : name(name), studentID(studentID), course(courseCode, courseName) {}
        void describe(){
            cout << "Name: " << name << endl;
            cout << "Student ID: " << studentID << endl;
            course.describe();
        }

};

int main(){
    Student student1("Jose Peterson", 128456, 102, "Introduction to Computer Science");
    student1.describe();
}