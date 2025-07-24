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
	cout << "1. �������� ���" << endl;
	cout << "2. �������� ������" << endl;
	cout << "3. �������� ������ ���������" << endl;
	cout << "4. ��������/�������� ����� ��������" << endl;
	cout << "5. ��������/�������� ����������� �����" << endl;
	cout << "6. ��������/�������� ���� ��������" << endl;
	cout << "0. Exit" << endl;
	cout << endl;
	cout << "Enter your choice: ";
	int ch;
	cin >> ch;
	switch (ch)
	{
	case 1: {
		string value;
		cout << "������� ����� ���: ";
		cin >> value;
		nameStudent = value;
		break;
	}
	case 2: {
		cout << "������� ����� ������: ";
		for (int i = 0; i < 5; i++)
		{
			cin >> grades[i];
		}

		break;
	}
	case 3: {
		cout << "������� ����� ������ ���������: ";
		cin >> money;
		break;
	}
	case 4: {
		cout << "������� ����� ��������: ";
		cin >> phone;
		break;
	}
	case 5: {
		cout << "������� ��.�����: ";
		cin >> email;
		break;
	}
	case 6: {
		cout << "������� ���� ��������: ";
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

	out << "���: " << nameStudent << endl;
	out << "����� ������: " << grnum << endl;
	out << "5 ��������� ������: ";
	for (int i = 0; i < 5; i++)
	{
		cout << grades[i] << " ";
	}
	out << endl;
	out << "������ ���������: " << money << endl;
	if (phone != "") {
		out << "����� ��������: " << phone << endl;
	}
	if (birthDay != "") {
		out << "���� ��������: " << birthDay << endl;
	}
	if (email != "") {
		out << "����������� �����: " << email << endl;
	}
}
