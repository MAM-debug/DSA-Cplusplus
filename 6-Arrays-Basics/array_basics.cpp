#include <iostream>
#include <string>
using namespace std;

    //objects: any real world entity is called object
    //class: definition of object is called class
    //example: car is object,its adjectives are called class
    // helps in re usability,scalability,maintainability
    class Teacher {
        //properties or attributes
        private:
        float salary;
        public://can be accessed outside the class and by default it is private
        string name;
        string dept;
        string subject;
        int experience;

        //methods or functions or member functions
        void Changedept (string newdept) {
            dept = newdept;
        }

        void setSalary (float s) {
            salary = s;
        }
        float getSalary () {
            return salary;
        }   
    };
int main (){
    Teacher t1;
    t1.name="Abdullah mateen";
    t1.dept="Computer Science";
    t1.subject="Data Structures";
    t1.experience=5;
    t1.setSalary(10);
    cout<<"salary of "<<t1.name<<" is "<<t1.getSalary()<<endl;
}
