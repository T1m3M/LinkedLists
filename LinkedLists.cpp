#include <bits/stdc++.h>
#include <cstddef>

using namespace std;

class Student{
private:
    string name;
    string department;
    int numOfCourses;

public:
    Student(){}
    Student(string n, string dept, int num){
        name = n;
        department = dept;
        numOfCourses = num;
    }
    int getNumOfCourses(){return numOfCourses;}

    friend ostream& operator<<(ostream& out, const Student& s){
        out << "Student name: " << s.name << endl;
        out << "Department: " << s.department << endl;
        out << "Number of courses: " << s.numOfCourses << endl;

        return out;
    }
};

class Course{
private:
    string courseName;
    int total;
    char grade;
    float point;

public:
    Course(){}
    Course(string cn, int t, char g, float po){
        courseName = cn;
        total = t;
        grade = g;
        point = po;
    }

    friend ostream& operator<<(ostream& out, const Course& c){
        out << "Course name: " << c.courseName << endl;
        out << "Total: " << c.total << endl;
        out << "Grade: " << c.grade << endl;
        out << "Point: " << c.point << endl;

        return out;
    }
};


class CourseList{
    struct crsNode{
        Course data;
        crsNode *next = NULL;
    };

    crsNode *head;
    crsNode *tail;
    int length;

public:
    CourseList(){
        head = tail = new crsNode;
        length = 0;
    }

    void addCourse(Course crs){
        crsNode *newcrsNode = new crsNode;
        newcrsNode->data = crs;

        if(length == 0){
            head = tail = newcrsNode;
        }
        else{
            tail->next = newcrsNode; /// put after tail
            tail = newcrsNode; /// update the tail
        }

        length++;
    }

    void print(){
        crsNode *it = head;

        for(int i=0; i < length; i++){

            cout << it->data << endl;
            it = it->next;
        }
    }

};

class StudentList{
private:
    struct studNode{
        Student data;
        CourseList *courses = NULL;
        studNode *next = NULL;
    };

    studNode *head;
    studNode *tail;
    int length;


public:

    StudentList(){
        head = tail = new studNode;
        length = 0;
    }

    void addStudent(Student stud, CourseList& crs){
        studNode *newstudNode = new studNode; /// initialize a new node
        newstudNode->data = stud; /// pointer to student
        newstudNode->courses = &crs; /// pointer to the courses linked list

        if(length == 0){
            head = tail = newstudNode;
        }
        else{
            tail->next = newstudNode; /// put after tail
            tail = newstudNode; /// update the tail
        }

        length++;
    }

    void print(){
        studNode *it = head;

        for(int i=0; i < length; i++){

            cout << it->data << endl;
            it->courses->print();
            cout << "-----------------" << endl;

            it = it->next;
        }
    }

};

int main(){

    StudentList allStudents;
    CourseList firstCrss;

    /// the first student
    Student firstStud("John Doe", "CS", 3);

    // initializing and adding the first student's courses
    // to the courses linked list
    Course crs01("Data Structure", 88, 'A', 3.7);
    firstCrss.addCourse(crs01);

    Course crs02("Data Base", 72, 'B', 2.88);
    firstCrss.addCourse(crs02);

    Course crs03("Simulation", 65, 'C', 2.5);
    firstCrss.addCourse(crs03);

    // adding the student info to the student linked list
    allStudents.addStudent(firstStud, firstCrss);
    CourseList secondCrss;


    /// the second student
    Student secondStud("Ahmed Sami", "IT", 1);

    Course crs11("Signals", 60, 'D', 2.4);
    secondCrss.addCourse(crs11);

    allStudents.addStudent(secondStud, secondCrss);


    /// print students courses and grades
    allStudents.print();

    return 0;
}
