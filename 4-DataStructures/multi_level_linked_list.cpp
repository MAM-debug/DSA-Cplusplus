#include <iostream>
using namespace std;



struct sNode {
    int studentID;
    sNode* nextStudent;
};

struct cNode {
    int courseID;
    cNode* nextCourse;
    sNode* StuList;
};

cNode* chead = nullptr;

void addCourse(int id) {
    cNode* newCourse = new cNode;
    newCourse->courseID = id;
    newCourse->StuList = nullptr;
    newCourse->nextCourse = nullptr;

    if (chead == nullptr) {
        chead = newCourse;
    } else {
        cNode* temp = chead;
        while (temp->nextCourse != nullptr) {
            temp = temp->nextCourse;
        }
        temp->nextCourse = newCourse;
    }
}

void addStudent(int cID, int sID) {
    cNode* ctemp = chead;

    while (ctemp != nullptr && ctemp->courseID != cID) {
        ctemp = ctemp->nextCourse;
    }

    if (ctemp == nullptr) {
        cout << "Course not found\n";
        return;
    }

    sNode* newStudent = new sNode;
    newStudent->studentID = sID;
    newStudent->nextStudent = nullptr;

    if (ctemp->StuList == nullptr) {
        ctemp->StuList = newStudent;
    } else {
        sNode* stemp = ctemp->StuList;
        while (stemp->nextStudent != nullptr) {
            stemp = stemp->nextStudent;
        }
        stemp->nextStudent = newStudent;
    }
}

void Display() {
    cNode* ctemp = chead;

    while (ctemp != nullptr) {
        cout << "Course " << ctemp->courseID << ": ";

        sNode* stemp = ctemp->StuList;
        if (stemp == nullptr) {
            cout << "No Students";
        }

        while (stemp != nullptr) {
            cout << stemp->studentID << " ";
            stemp = stemp->nextStudent;
        }

        cout << endl;
        ctemp = ctemp->nextCourse;
    }
    

}
int main (){
    addCourse(105);
    addCourse(108);
    addStudent(108,74);
    addStudent(108,66);
    Display();
}


































