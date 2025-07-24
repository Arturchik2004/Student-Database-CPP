#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Student {
private:
    float sum;
    string nameStudent;
    int grnum;
    string email, phone, birthDay;
    int grades[5];
    float money;
    Student* next;
    Student* prev;
public:
    Student(string name, int groupnum, int lastfivemarks[5], float stipend);
    string get_FIO();
    int get_groupnum();
    int* get_grades();
    float get_money();
    float get_sum();
    void set_groupnum(int ndata);
    Student* get_next();
    void set_next(Student* nextn);
    void changeInfo();
    Student* get_prev();
    void set_prev(Student* nextn);
    void displayInfo(ostream& out);
    string get_birth();
    string get_phone();
    string get_email();
    void set_phone(string value);
    void set_email(string value);
    void set_birth(string value);
};

