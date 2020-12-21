// lab10.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Варіант 9.
//Є текстовий файл, що містить список товарів.Для кожного товару вказані його назва,
//назва магазину, в якому продається товар, вартість одиниці товару в гривнях і його кількість з
//вказівкою одиниці вимірювання(наприклад, кількість: 100 шт., одиниця вимірювання :
//упаковка по 20 кг.).
//Написати програму, що виконує наступні дії :
// створює, переглядає та поповнює список;
// здійснює виведення на екран інформації про товари, що продаються в магазині,
//назва якого введена з клавіатури;
// здійснює виведення на екран інформації про товари із заданого з клавіатури
//діапазону вартості.

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;


struct Store
{
	string store_name;
	string item_name;
	double price; 
	int items_count;  
	double weight;
};


void fillingfile(const string fname,int optiion);
void printfile(const string fname);
void searchnamestore(const string fname,const string namestore);
void searchnameitem(const string fname, double high, double low);
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string fname;
	string s, namest;

	double highprice;
	double lowprice;
	int d;
	cout << "Введіть назву файла: "; getline(cin, fname);
	do
	{
		cout << endl;
		cout << "Виберіть дію" << endl;
		cout << "1- введення даних про товар " << endl;
		cout << "2- поповнення списку " << endl;
		cout << "3- вивід даних на екран " << endl;
		cout << "4- пошук товарів за імям магазину " << endl;
		cout << "5- пошук товарів з діапазону ціни" << endl;
		cout << "0- вихід " << endl;
		cin >> d;
		switch (d) 
		{
		case 1:
			fillingfile(fname, 1);
			break;
		case 2:
			fillingfile(fname, 2);
			break;
		case 3:
			printfile(fname);
			break;
		case 4:
			cout << "Введіть назву магазину: ";
			cin.get();
			cin.sync();
			getline(cin, namest);

			searchnamestore(fname, namest);
			break;
		case 5:
			cout << "Введіть нижній діапазон ціни :"; cin >> lowprice;
			cout << endl;
			cout << "Введіть верхній діапазон ціни :"; cin >> highprice;
			cout << endl;

			searchnameitem(fname, highprice, lowprice);
			break;
		case 0:
			
			exit(1);
		default:
			cout << "Такого пункту немає!!!!!" << endl;
			break;

		}

	} while (d!=0);

}
void searchnameitem(const string fname, double high, double low)
{
	char ch1[100];
	char ch2[100];
	
	double g;


	int num = 1;

	ifstream file(fname, ios::in);
	if (!file.is_open()) {
		cout << "Файл не відкрився !!!";
		return;
	}
	cout << "=================================================================================================" << endl;
	cout << "| № |  Назва магазину  |  Назва товару  |  Вартість товару  |  Кількість товару  |  Вага товару  |" << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	while (!file.eof())
	{
		file.getline(ch1, sizeof(ch1));
		file.getline(ch2, sizeof(ch2));
		file >> g;
		
		if (g >low && g < high)
		{
			cout << "|" << setw(2) << num++ << setw(2) << "|";

			
			cout <<  setw(9) << ch1 << setw(10) << "|";

			
			cout <<  setw(9) << ch2 << setw(8) << "|";

			
			cout <<  setw(10) << g << setw(10) << "|";

			file.getline(ch1, sizeof(ch1));
			cout <<  setw(10) << ch1 << setw(11) << "|";

			file.getline(ch2, sizeof(ch2));
			cout <<  setw(8) << ch2 << setw(8) << "|"<<endl;
		}
		else
		{
			for (int i = 0;  i<2 ; i++)
			{
				file.getline(ch1, sizeof(ch1));
			}
		}
	}
	cout << "=================================================================================================" << endl;
}
void searchnamestore(const string fname, const string namestore)
{
	char ch[60];
	
	int num = 1;
	ifstream file(fname, ios::in);
	if (!file.is_open()) {
		cout << "Файл не відкрився!!";
		return;
	}
	cout << "=================================================================================================" << endl;
	cout << "| № |  Назва магазину  |  Назва товару  |  Вартість товару  |  Кількість товару  |  Вага товару  |" << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;

	while (!file.eof())
	{
		file.getline(ch, sizeof(ch));

		if (ch == namestore)
		{
			cout << "|" << setw(2) << num++ << setw(2) << "|";

			//file.getline(ch, sizeof(ch));
			cout <<  setw(9) << ch << setw(10) << "|";

			file.getline(ch, sizeof(ch));
			cout <<  setw(9) << ch << setw(8) << "|";

			file.getline(ch, sizeof(ch));
			cout <<  setw(10) << ch << setw(10) << "|";

			file.getline(ch, sizeof(ch));
			cout <<  setw(10) << ch << setw(11) << "|";

			file.getline(ch, sizeof(ch));
			cout <<  setw(8) << ch << setw(8) << "|"<<endl;
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				file.getline(ch, sizeof(ch));
			}
		}
	}
	cout << "=================================================================================================" << endl;

}
void printfile(const string fname)
{
	ifstream file(fname,ios::in);
	string str;
	int count=0;
	if (!file.is_open())
	{
		cout << "Файл не відкрився !!!";
		return;
	}
	int num = 1;
	char ch[100];
	cout << "=================================================================================================" << endl;
	cout << "| № |  Назва магазину  |  Назва товару  |  Вартість товару  |  Кількість товару  |  Вага товару  |" << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;

	while (!file.eof())
	{
		getline(file, str);//визначаємо кількість рядків в файлі
		count ++;
	}

	file.close();
	file.open(fname, ios::in);
	for (int i = 0; i < count/5; i++)
	{
		cout << "|" << setw(2) << num++ << setw(2) << "|";

		file.getline(ch, sizeof(ch));
		cout <<  setw(9) << ch << setw(10) << "|";

		file.getline(ch, sizeof(ch));
		cout <<  setw(9) << ch << setw(8) << "|";

		file.getline(ch, sizeof(ch));
		cout <<  setw(10) << ch << setw(10) << "|";

		file.getline(ch, sizeof(ch));
		cout <<  setw(10) << ch << setw(11) << "|";

		file.getline(ch, sizeof(ch));
		cout << setw(8) << ch << setw(8) << "|"<<endl;

	}
	cout << "=================================================================================================" << endl;
}
void fillingfile(const string fname, int optiion)
{
	Store store;
	string strt;
	ofstream file;


	
	switch (optiion)
	{
	case 1:
		file.open(fname, ios::out);
		break;
	case 2:
		file.open(fname, ios::app);
		break;
	}
	if (!file.is_open())
	{
		cout << "Файл не відкрився !!!";
		return;
	}

	cin.get();
	cin.sync();
	do
	{
		
		cout << endl;
		cout << "Введіть назву магазину: "; getline(cin, store.store_name);
		file << store.store_name << endl;

		cout << "Введіть назву товару: "; getline(cin, store.item_name);
		file << store.item_name << endl;

		cout << "Введіть ціну одиниці товару: "; cin >> store.price;
		file << store.price << endl;

		cout << "Введіть кількість одиниць в магазині: "; cin >> store.items_count;
		file << store.price << endl; 

		cout << "Введіть вагу одиниці товару: "; cin >> store.weight;
		file << store.price << endl;

		cin.get();
		cout << "Введіть 'yes' щоб продовжити або 'no' щоб завершити: ";
		getline(cin, strt);

	} while (strt=="Yes"||strt=="yes");
}
//   ___
//  |___|
//  ['_']
//  /| | \
// ||___|/_
//  \\_____|--------    *                  *             *             
//   // \
    //   \
//  |_   \_
//
