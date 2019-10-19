#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class Student {
    int grade;
    string name;
    public:
        Student(int g, string n) : grade(g), name(n) {};
        int getGrade();
        void setGrade(int g);
        string getName();
        bool operator > (const Student &s1) const;
};

class StudentManager {
    list<Student*> students;
    public:
        void addStudent(int grade, string name);    // 增加学生
        void updateGrade(int grade, string name);   // 增加学生成绩
        int findGrade(string name); // 查找学生成绩
        void S_sort();  // 对学生成绩排序
};

int Student::getGrade() {
    return grade;
}

void Student::setGrade(int g) {
    grade = g;
}

string Student::getName() {
    return name;
}

bool Student::operator>(const Student &s1) const {
    return this->grade > s1.grade;
}

void StudentManager::addStudent(int grade=0, string name) {
    students.push_back(new Student(grade, name));
}

void StudentManager::updateGrade(int grade, string name) {
    for(auto it = students.begin(); it != students.end(); ++it) {
        if((*it)->getName() == name) {
            (*it)->setGrade(grade);
        }
    }
}

int StudentManager::findGrade(string name) {
    for(auto it = students.begin(); it != students.end(); ++it) {
        if((*it)->getName() == name) {
            return (*it)->getGrade();
        }
    }
}

void StudentManager::S_sort() {
    sort(students.begin(), students.end());
}