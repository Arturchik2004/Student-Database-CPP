#include <iostream>
#include <string>
#include <fstream>
#include "DLinkedList.h";
using namespace std;
int main(int argc, char* argv[]) {
	string str, ostr;


	str = "input.txt";
	ostr = "output.txt";
	setlocale(LC_ALL, "ru");
	/*str = string(argv[1]) + ".txt";
	ostr = string(argv[2]) + ".txt";*/
	ifstream fin;
	ofstream fout;
	fout.open(ostr);
	fin.open(str);
	ostream* ou = &cout;
	char delimiter; // для запятой
	string fio;
	int groupnum;
	int out;
	int arr[5];
	float money;
	int choice;
	int mode;
	DLinkedList b;
	cout << "Ввод через: 1 файл \n";
	cout << "Ввод через: 2 консоль \n";
	cin >> mode;

	switch (mode) {
	case 1:
	{
		while (true) {
			if (!(fin >> fio)) break; // Считываем ФИО
			if (!(fin >> groupnum)) break; // Считываем группу
			for (int i = 0; i < 5; ++i) {
				if (!(fin >> arr[i])) break; // Считываем оценки
			}
			if (!(fin >> money)) break; // Считываем стипендию
			if (!(fin >> delimiter)) break;
			b.addStudent(fio, groupnum, arr, money);
		}
		cout << "Вывод в консоль: 1 \n";
		cout << "Вывод в файл: 2 \n";
		cin >> out;
		switch (out) {
		case 1: {
			ou = &cout;
			break;
		}
		case 2: {
			if (fout.is_open()) {
				ou = &fout;
			}
			else {
				cerr << "Ошибка открытия файла." << endl;
			}
			break;
		}
		default: {
			break;
		}
			   break;
		}
	case 2:
	{
		do {
			cout << "1. Добавить студента" << endl;
			cout << "2. Показать всех студентов в группе" << endl;
			cout << "3. Удалить студента из группы" << endl;
			cout << "4. Показать всех студентов" << endl;
			cout << "5. Удалить группу" << endl;
			cout << "6. Редактировать информацию" << endl;
			cout << "7. 9 Вариант" << endl;

			cout << "0. Exit" << endl;
			cout << endl;
			cout << "Enter your choice: ";
			cin >> choice;

			switch (choice) {
			case 1: {
				cout << "Напишите ФИО : ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, fio, '\n');
				if (fio.length() > 50) {
					fio = fio.substr(0, 50);
				}
				cout << "Напишите номер группы: ";
				cin >> groupnum;

				cout << "Какие у вас последние 5 оценок?: ";
				for (int i = 0; i < 5; i++)
				{
					cin >> arr[i];
				}
				cout << "Какова твоя стипендия? : ";
				cin >> money;
				cout << endl;
				b.addStudent(fio, groupnum, arr, money);
				break;
			}
			case 2: {
				cout << "Какую группу вам показать?: ";
				cin >> groupnum;
				b.displayGroup(groupnum, *ou);
				break;
			}
			case 3: {
				cout << "Введите группу: ";
				cin >> groupnum;
				cout << endl;
				cout << "Введите ФИО: ";
				cin >> fio;
				b.deleteStudent(fio, groupnum, *ou);
				break;
			}
			case 4: {
				b.displayStudents(*ou);
				break;
			}
			case 5: {
				cout << "Какую группу удалить?: ";
				cin >> groupnum;
				b.deleteGroup(groupnum);
				break;
			}
			case 6: {
				cout << "Введите номер группы и ФИО: " << endl;
				int grup;
				string name;
				cin >> grup;
				cin >> name;
				b.newInfo(grup, name);
				break;
			}
			case 7: {
				cout << "Вывести перечень групп потока с указанием (для каждой группы) процента суммарной стипендии группы по отношению к суммарной стипендии потока : " << endl;				
				b.nine(*ou);
				break;
			}
			default: {
				cout << "Какая-то ерунда. Попробуйте ещё раз." << endl;
				break;
			}
			}

		} while (choice != 0);
		if (fout.is_open()) {
			fout.close();
		}
		break;
	}

	}
	}
}