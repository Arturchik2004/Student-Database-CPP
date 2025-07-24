#include <iostream>
#include <string>
#include <fstream>
#include "DLinkedList.h";
using namespace std;


void  DLinkedList::newInfo(int gr, string fio) {
    Student* curr = Students;
    while (curr) {
        if (curr->get_groupnum() == gr and curr->get_FIO() == fio) {
            break;
        }
        curr = curr->get_next();
    }
    if (curr == nullptr) {
        cout << "Такого студента нет" << endl;
    }
    else {
        curr->changeInfo();
    }
}



DLinkedList::DLinkedList() { //для добавления первого студента
    Students = NULL;
}

float DLinkedList::GetCount(int group)
{
    int arr[26]{};
    float sumG = 0;
    Student* curr = Students;
    while (curr) {
        if (curr->get_groupnum() == group) {
            sumG = sumG+curr->get_money();
        }
        curr = curr->get_next();
    }
    return sumG;
}

void DLinkedList::nine(ostream& out) {
    int arr[26]{ -1 };
    int b = 0;
    Student* curr = Students;
    bool th = false;
    while (curr) {
        for (int i = 0; i < 26; i++) {
            if (curr->get_groupnum() == arr[i]) {
                th = true;
                break;
            }
            else {
                th = false;
            }
        }
        if (th == false) {
            float sum = (GetCount(curr->get_groupnum()) * 100) / big();
            out << "Группа номер " << curr->get_groupnum() << " Размер стипендии в процентах " << sum << endl;
            arr[b] = curr->get_groupnum();
            b++;
        }
        curr = curr->get_next();
    }

}



float DLinkedList::big()
{
    float big = 0;
    Student* curr = Students;
    while (curr) {
        big += curr->get_money();
        curr = curr->get_next();
    }
    return big;
}

void DLinkedList::addStudent(string name, int groupnum, int lastfivemarks[5], float stipend) {// функция для добавления студента
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        arr[i] = lastfivemarks[i];
    }
    Student* newNode = new Student(name, groupnum, arr, stipend);
    if (Students == NULL) {
        Students = newNode;
    }
    else {
        Student* current = Students;
        while (current->get_next() != NULL) {

            current = current->get_next();
        }
        current->set_next(newNode); //указываем на нового студента
        newNode->set_prev(current); //указываем на предыдущего студента
    }
    count++;
}

void DLinkedList::deleteGroup(int groupnum) //функция для удаления группы
{
    Student* current = Students;
    while (current != NULL) {
        if (current->get_groupnum() == groupnum) {
            Student* temp = current;
            delete temp;
        }
        current = current->get_next();
    }
}

void DLinkedList::deleteStudent(string fio, int group, ostream& out) { //функция для удаления студента
    Student* current = Students;
    while (current != NULL) {
        if (current->get_FIO() == fio && current->get_groupnum() == group) {
            delete current;
            out << "Человек найден и удалён!" << endl;
            break;
        }
        current = current->get_next();
    }
}
void DLinkedList::displayStudents(ostream& out) { //показывает всех студентов
    Student* current = Students;
    if (current == NULL) {
        out << "Группа пуста" << endl;
    }
    while (current != NULL) {
        current->displayInfo(out);
        out << endl;
        current = current->get_next();
    }
}

void DLinkedList::displayGroup(int groupnum, ostream& out) { //показывает всю группу
    Student* current = Students;
    if (current == NULL) {
        out << "Группа пуста" << endl;
    }
    while (current != NULL) {
        if (current->get_groupnum() == groupnum) {
            current->displayInfo(out);
            out << endl;
        }
        current = current->get_next();
    }
}