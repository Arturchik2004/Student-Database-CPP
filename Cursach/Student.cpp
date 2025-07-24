#include <iostream>
#include <string>
#include "Student.h"
#include <cstring>
Student::Student(string name, int groupnum, int lastfivemarks[5], float date)
{
    nameStudent = name;
    grnum = groupnum;
    for (int i = 0; i < 5; i++)
    {
        grades[i] = lastfivemarks[i];
    }
    money = date;
    sum += money;
    next = nullptr;
    prev = nullptr;
}

string Student::get_FIO() {
    return nameStudent;
}
string Student::get_phone() {
	return phone;
}
string Student::get_email() {
	return email;
}
string Student::get_birth() {
	return birthDay;
}
int Student::get_groupnum()
{
    return grnum;
}
float Student::get_sum()
{
    return sum;
}
int* Student::get_grades()
{
    return grades;
}

float Student::get_money()
{
    return money;
}

void Student::set_groupnum(int ndata)
{
    grnum = ndata;
}

Student* Student::get_next()
{
    return next;
}

void Student::set_next(Student* nextn)
{
    next = nextn;
}

Student* Student::get_prev() {
    return prev;
}

void Student::set_email(string value) {
	email = value;
}
void Student::set_birth(string value) {
	birthDay = value;
}
void Student::set_phone(string value) {
	phone = value;
}



void Student::changeInfo() {
	cout << "1. Изменить ФИО" << endl;
	cout << "2. Изменить оценки" << endl;
	cout << "3. Изменить размер стипендии" << endl;
	cout << "4. Изменить/Добавить номер телефона" << endl;
	cout << "5. Изменить/Добавить электронную почту" << endl;
	cout << "6. Изменить/Добавить дату рождения" << endl;
	cout << "0. Exit" << endl;
	cout << endl;
	cout << "Enter your choice: ";
	int ch;
	cin >> ch;
	switch (ch)
	{
	case 1: {
		string value;
		cout << "Введите новое ФИО: ";
		cin >> value;
		nameStudent = value;
		break;
	}
	case 2: {
		cout << "Введите новые оценки: ";
		for (int i = 0; i < 5; i++)
		{
			cin >> grades[i];
		}

		break;
	}
	case 3: {
		cout << "Введите новый размер стипендии: ";
		cin >> money;
		break;
	}
	case 4: {
		cout << "Введите номер телефона: ";
		cin >> phone;
		break;
	}
	case 5: {
		cout << "Введите эл.почту: ";
		cin >> email;
		break;
	}
	case 6: {
		cout << "Введите дату рождения: ";
		cin >> birthDay;
		break;
	}
	default:
		break;
	}

}

void Student::set_prev(Student* p) {

    prev = p;
}

void Student::displayInfo(ostream& out) {

	out << "ФИО: " << nameStudent << endl;
	out << "Номер группы: " << grnum << endl;
	out << "5 последних оценок: ";
	for (int i = 0; i < 5; i++)
	{
		cout << grades[i] << " ";
	}
	out << endl;
	out << "Размер стипендии: " << money << endl;
	if (phone != "") {
		out << "Номер телефона: " << phone << endl;
	}
	if (birthDay != "") {
		out << "Дата рождения: " << birthDay << endl;
	}
	if (email != "") {
		out << "Электронная почта: " << email << endl;
	}
}
