#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>

using namespace std;

/* Класс подъемно-транспортные машины */
class Lifting_transporting_machines {
private:
	int lifting_power; // Грузоподъемность
	char* model = NULL; // Модель 
	int weight; // Вес
	int species; // Разновидность
	int type; // Тип

public:
	void defconstructor(); // Псевдоконструктор по умолчанию
	void constructor(char* Model, int Lifting_power, int Weight, int Species, int Type); // Псевдоконструктор с параметрами
	void Destructor(); // Псевдодеструктор

	void get_machines() const; // Вывод полей объекта класса
	void set_machines(); // Изменение полей объекта класса
	int get_lifting_power() const; // Метод, который возвращает значение поля frequency
	Lifting_transporting_machines& copy(const Lifting_transporting_machines& s); // Метод копирования полей одно объекта в другой

};

/* Класс-контейнер в виде статической матрицы */
class matrix {
private:
	const int size = 2; // размер матрицы
	Lifting_transporting_machines matrix[2][2]; // сама матрица
public:
	void Dest(); // Деструктор контейнера
	void set_matrix(); // Заполнение матрицы
	void enter_matrix(); // Изменение элементов матрицы
	void get_matrix() const; // Вывод элементов матрицы
	void search() const; // Поиск
	void compare() const; // Сравнение
	void sort(); // Сортировка
};

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));

	matrix m; // объявляем матрицу
	m.set_matrix(); // заполняем матрицу
	m.get_matrix(); // выводим матрицу
	system("pause");
	system("cls");

	m.enter_matrix(); // изменям поля объекстам внутри матрицы
	system("cls");
	m.get_matrix(); // выводим матрицу
	system("pause");
	system("cls");

	m.search(); // поиск по грузоподъемности
	system("pause");
	system("cls");

	m.compare(); // сравнение по грузоподъемности
	system("pause");
	system("cls");

	m.sort(); // сортировка по грузоподъемности (от меньшего к большему)
	m.get_matrix(); // выводим матрицу

	m.Dest(); // вызываем дутруктор


	system("pause");
	return 0;
}

void Lifting_transporting_machines::defconstructor() //Псевдоконструктор по умолчанию
{
	char Default[] = "default";
	model = new char[strlen(Default) + 1];
	strcpy_s(model, strlen(Default) + 1, Default);

	lifting_power = 0;
	weight = 0;
	species = 0;
	type = 0;
}

void Lifting_transporting_machines::constructor(char* Model, int Lifting_power, int Weight, int Species, int Type) // Псевдоконструктор с параметрами
{
	model = new char[strlen(Model) + 1];
	strcpy_s(model, strlen(Model) + 1, Model);

	lifting_power = Lifting_power;
	weight = Weight;
	species = Species;
	type = Type;
}

void Lifting_transporting_machines::Destructor() // Псевдодеструктор
{
	if (model != NULL) delete[] model;
}

void Lifting_transporting_machines::get_machines() const  // Вывод полей класса
{
	cout << "_______________________________________\n";
	cout << "Грузоподъемность: " << lifting_power << endl;
	cout << "Модель: " << model << endl;
	cout << "Вес: " << weight << endl;
	cout << "Разновидность: " << species << endl;
	cout << "Тип: " << type << endl;
}

void Lifting_transporting_machines::set_machines()  // Изменение полей класса
{
	char str[30];
	cout << "Введите модель: "; cin >> str;

	if (model != NULL) delete[] model;
	model = new char[strlen(str) + 1];
	strcpy_s(model, strlen(str) + 1, str);

	lifting_power = rand() % 100;
	weight = rand() % 100;
	species = rand() % 100;
	type = rand() % 100;

}

int Lifting_transporting_machines::get_lifting_power() const // Метод, который возвращает значение поля lifting_power
{
	return lifting_power;
}

Lifting_transporting_machines& Lifting_transporting_machines::copy(const Lifting_transporting_machines& s) // Метод копирования полей одно объекта в другой
{
	if (this != &s) {
		if (model != NULL) delete[] model;
		if (s.model != 0) {
			model = new char[strlen(s.model) + 1];
			strcpy_s(model, strlen(s.model) + 1, s.model);
		}
		lifting_power = s.lifting_power;
		weight = s.weight;
		species = s.species;
		type = s.type;
	}
	return *this;
}

void matrix::Dest() // Деструктор контейнера
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j].Destructor();
		}
	}
}

void matrix::set_matrix() // Заполнение матрицы
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j].defconstructor();
		}
	}
}

void matrix::enter_matrix() // Изменение элементов матрицы
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j].set_machines();
		}
	}
}

void matrix::get_matrix() const // Вывод элементов матрицы
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j].get_machines();
		}
	}
	cout << "_______________________________________\n";
}

void matrix::search() const // Поиск
{
	int lifting;
	cout << "ПОИСК\nВведите грузоподъемность: "; cin >> lifting;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (matrix[i][j].get_lifting_power() == lifting) {
				matrix[i][j].get_machines();
			}
		}
	}
}

void matrix::compare() const // Сравнение
{
	int lifting;
	cout << "ПОИСК\nВведите грузоподъемность: "; cin >> lifting;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (matrix[i][j].get_lifting_power() >= lifting) {
				matrix[i][j].get_machines();
			}
		}
	}
}

void matrix::sort() // Сортировка
{
	Lifting_transporting_machines* mas = new Lifting_transporting_machines[size * size];
	for (int i = 0; i < size * size; i++) {
		mas[i].defconstructor();
	}
	int g = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			mas[g++].copy(matrix[i][j]);
		}
	}
	for (int i = 0; i < g - 1; i++) {
		for (int j = i + 1; j < g; j++) {
			if (mas[i].get_lifting_power() > mas[j].get_lifting_power()) {
				swap(mas[i], mas[j]);
			}
		}
	}
	g = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j].copy(mas[g++]);
		}
	}
	delete[] mas;
}
