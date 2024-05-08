#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Member{
    public:
        string name;
        int birth_year;
        
        Member(string name, int birth_year):name(name), birth_year(birth_year){}
        virtual ~Member(){}
};
class Participant:public Member{
    public:
        string field;
        
        Participant(string name, int birth_year, string field)
            : Member(name, birth_year), field(field){}
        
        void describe(){
            cout << "Participant - Name: " << name << " - year of Birth: " << birth_year << " - Field: " << field << endl;
        }
};

class Mentor:public Member{
    public:
        string subject;

        Mentor(string name, int birth_year, string subject)
            : Member(name, birth_year), subject(subject){}
        void describe(){
            cout << "Participant - Name: " << name << " - year of Birth: " << birth_year << " - Subject: " << subject << endl;
        }
};

class Coordinator : public Member{
    public:
        string division;

        Coordinator(string name, int birth_year, string division)
            : Member(name, birth_year), division(division){}
        void describe(){
            cout << "Participant - Name: " << name << " - year of Birth: " << birth_year << " - Division: " << division << endl;
        }
};

class Society{
    public:
        string name;
        vector <Member*> members;

        Society(string name): name(name){}
        /*Society class has a vector of pointers to Member objects,
        and a method addMember to add a new member to the society.
        The destructor of Society deletes all member objects to avoid memory leaks.*/
        ~Society(){
            for (Member* member: members) {
                delete member;
            }
        }

        void addMember(Member* member) {
            members.push_back(member);
        }
        int countCoordinators() const {
            int count = 0;
            for (const Member* member : members) {
                if (dynamic_cast<const Coordinator*>(member) != nullptr) {
                    count++;
                }
            }
            return count;
        }
        void sortBirthYear() {
            std::sort(members.begin(), members.end(), [](const Member* a, const Member* b) {
                return a->birth_year < b->birth_year;
            });
        }

        double aveMentorYearOfBirth() const {
            int sum = 0;
            int count = 0;
            for (const Member* member : members) {
                const Mentor* mentor = dynamic_cast<const Mentor*>(member);
                if (mentor != nullptr) {
                    sum += mentor->birth_year;
                    count++;
                }
            }
            return count > 0 ? static_cast<double>(sum) / count : 0;
        }
        void describe() const {
            cout << "Society: " << name << endl;
            for (const Member* member : members) {
                const Participant* participant = dynamic_cast<const Participant*>(member);
                const Mentor* mentor = dynamic_cast<const Mentor*>(member);
                const Coordinator* coordinator = dynamic_cast<const Coordinator*>(member);
                if (participant != nullptr) {
                    cout << "Participant: " << participant->name << ", " << participant->birth_year << ", " << participant->field << endl;
                } else if (mentor != nullptr) {
                    cout << "Mentor: " << mentor->name << ", " << mentor->birth_year << ", " << mentor->subject << endl;
                } else if (coordinator != nullptr) {
                    cout << "Coordinator: " << coordinator->name << ", " << coordinator->birth_year << ", " << coordinator->division << endl;
                }
            }
        }
};

int main(){
    Participant participant("Alice", 1995, "Art");
    participant.describe();

    Mentor mentor1("Bob", 1980, "Math");
    mentor1.describe();

    Mentor mentor2("Carol", 1970, "Science");
    mentor2.describe();
    
    Coordinator coordinator1("David", 1985, "Events");
    Coordinator coordinator2("Thomas", 1980, "Logistics");

     // Create a society with name = "society1"
    Society society("society1");
    // add 1 participant, 2 mentor, 2 coordinator
    society.addMember(&participant);
    society.addMember(&mentor1);
    society.addMember(&mentor2);
    society.addMember(&coordinator1);
    society.addMember(&coordinator2);
 
    // describe
    society.describe();

    // Use countCoordinator() method to count
    // number of people and store result
    // in numberOfCoordinators variable
    int numberOfCoordinators = society.countCoordinators();
    cout << "numberOfCoordinators: " << numberOfCoordinators << endl;
    
    //Sort people in the society by their age
    society.sortBirthYear();
    //use sortAge() method to sort
    society.describe();
    
    // Use aveMentorYearOfBirth() method to calculate average year of birth of Mentors
    //and store the result
    //in aveMentorYearOfBirth variable
    double aveMentorYearOfBirth = society.aveMentorYearOfBirth();
    cout << "Average year of birth(Mentors): " << aveMentorYearOfBirth << endl;
    
    return 0;
}