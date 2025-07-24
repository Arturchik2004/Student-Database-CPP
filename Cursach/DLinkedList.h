#pragma once
#include <iostream>
#include "Student.h"
class DLinkedList {
private:
    Student* Students;
    int count = 0;
public:
    DLinkedList();
    float GetCount(int group);
    void nine(ostream& out);
    bool gr();
    float big();
    void addStudent(string name, int groupnum, int lastfivemarks[5], float stipend);
    void deleteGroup(int groupnum);
    void deleteStudent(string FIO, int group, ostream& out);
    void displayStudents(ostream& out);
    void newInfo(int gr, string fio);
    void displayGroup(int group, ostream& out);
};
