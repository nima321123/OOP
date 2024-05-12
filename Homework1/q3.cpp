#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Person {
public:
    string name;
    int yearOfBirth;

    Person(string name, int yearOfBirth) : name(name), yearOfBirth(yearOfBirth) {}

    virtual void describe() = 0;
};

class Student : public Person {
    string grade;

public:
    Student(string name, int yearOfBirth, string grade) : Person(name, yearOfBirth), grade(grade) {}

    void describe() override {
        cout << "Student: " << name << ", Year of Birth: " << yearOfBirth << ", Grade: " << grade << endl;
    }
};

class Teacher : public Person {
    string subject;

public:
    Teacher(string name, int yearOfBirth, string subject) : Person(name, yearOfBirth), subject(subject) {}

    void describe() override {
        cout << "Teacher: " << name << ", Year of Birth: " << yearOfBirth << ", Subject: " << subject << endl;
    }
};

class Doctor : public Person {
    string specialist;

public:
    Doctor(string name, int yearOfBirth, string specialist) : Person(name, yearOfBirth), specialist(specialist) {}

    void describe() override {
        cout << "Doctor: " << name << ", Year of Birth: " << yearOfBirth << ", Specialist: " << specialist << endl;
    }
};

class Ward {
    string name;
    vector<Person*> people;

public:
    Ward(string name) : name(name) {}

    void addPerson(Person* person) {
        people.push_back(person);
    }

    void describe() {
        cout << "Ward: " << name << endl;
        for (Person* person : people) {
            person->describe();
        }
    }

    int countDoctor() {
        return count_if(people.begin(), people.end(), [](Person* person) { return dynamic_cast<Doctor*>(person) != nullptr; });
    }

    void sortAge() {
        sort(people.begin(), people.end(), [](Person* a, Person* b) { return a->yearOfBirth > b->yearOfBirth; });
    }

    double aveTeacherYearOfBirth() {
        vector<Teacher*> teachers;
        for (Person* person : people) {
            Teacher* teacher = dynamic_cast<Teacher*>(person);
            if (teacher) {
                teachers.push_back(teacher);
            }
        }
        return accumulate(teachers.begin(), teachers.end(), 0.0, [](double sum, Teacher* teacher) { return sum + teacher->yearOfBirth; }) / teachers.size();
    }
};

int main(){
    Student student("studentA", 2010, "7");
    student.describe();

    Teacher teacher1("teacherA", 1969, "Math");
    teacher1.describe();

    Doctor doctor1("doctorA", 1945, "Endocrinologists");
    doctor1.describe();

    Teacher teacher2("teacherB", 1995, "History");
    Doctor doctor2("doctorB", 1975, "Cardiologists");

    Ward ward("Ward1");
    ward.addPerson(&student);
    ward.addPerson(&teacher1);
    ward.addPerson(&teacher2);
    ward.addPerson(&doctor1);
    ward.addPerson(&doctor2);
    ward.describe();

    int numberOfDoctors = ward.countDoctor();
    cout << "number of doctors: " << numberOfDoctors << endl;

    ward.sortAge();
    ward.describe();

    int aveTeacherYearOfBirth = ward.aveTeacherYearOfBirth();
    cout << "average year of birth (teachers): " << aveTeacherYearOfBirth << endl;
    
    return 0;
}