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
	Lifting_transporting_machines(); // конструктор по умолчанию
	Lifting_transporting_machines(char* Model, int Lifting_power, int Weight, int Species, int Type); // конструктор с параметрами
	~Lifting_transporting_machines();  // деструктор
	Lifting_transporting_machines(const Lifting_transporting_machines& s); // копирующий конструктор

	void set_machines(); // Изменение полей объекта класса
	int get_lifting_power() const; // Метод, который возвращает значение поля frequency
	void copy(const Lifting_transporting_machines& s); // Метод копирования полей одно объекта в другой

	Lifting_transporting_machines& operator=(Lifting_transporting_machines& s); // перегрузка оператора присваивания "="
	bool operator>(Lifting_transporting_machines& s); // перегрузка оператора сравнения больше ">"
	friend ostream& operator<<(ostream& out, const Lifting_transporting_machines& s); // перегрузка оператора вывода "cout << "

};

/* Класс-контейнер в виде статической матрицы */
class matrix {
private:
	const int size = 2; // размер матрицы
	Lifting_transporting_machines matrix[2][2]; // сама матрица
public:
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



	system("pause");
	return 0;
}

Lifting_transporting_machines::Lifting_transporting_machines() // конструктор поумолчанию
{
	char Default[] = "default";
	model = new char[strlen(Default) + 1];
	strcpy_s(model, strlen(Default) + 1, Default);

	lifting_power = 0;
	weight = 0;
	species = 0;
	type = 0;
}

Lifting_transporting_machines::Lifting_transporting_machines(char* Model, int Lifting_power, int Weight, int Species, int Type) // конструктор с параметрами
{
	model = new char[strlen(Model) + 1];
	strcpy_s(model, strlen(Model) + 1, Model);

	lifting_power = Lifting_power;
	weight = Weight;
	species = Species;
	type = Type;
}

Lifting_transporting_machines::~Lifting_transporting_machines() // деструктор
{
	if (model != NULL) delete[] model;
}

Lifting_transporting_machines::Lifting_transporting_machines(const Lifting_transporting_machines& s) // копирующий конструктор
{
	copy(s);
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

void Lifting_transporting_machines::copy(const Lifting_transporting_machines& s) // Метод копирования полей одно объекта в другой
{
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

Lifting_transporting_machines& Lifting_transporting_machines::operator=(Lifting_transporting_machines& s) // перегрузка оператора присваивания "="
{
	if (this != &s) {
		copy(s);
	}
	return *this;
}

bool Lifting_transporting_machines::operator>(Lifting_transporting_machines& s) // перегрузка оператора сравнения больше ">"
{
	return lifting_power > s.lifting_power;
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
			cout << matrix[i][j];
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
				cout << matrix[i][j];
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
				cout << matrix[i][j];
			}
		}
	}
}

void matrix::sort() // Сортировка
{
	Lifting_transporting_machines* mas = new Lifting_transporting_machines[size * size];
	int g = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			mas[g++] = matrix[i][j];
		}
	}
	for (int i = 0; i < g - 1; i++) {
		for (int j = i + 1; j < g; j++) {
			if (mas[i] > mas[j]) {
				Lifting_transporting_machines tmp(mas[i]);
				mas[i] = mas[j];
				mas[j] = tmp;
			}
		}
	}
	g = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = mas[g++];
		}
	}
	delete[] mas;
}

ostream& operator<<(ostream& out, const Lifting_transporting_machines& s) // перегрузка оператора вывода "cout << "
{
	out << "_______________________________________\n";
	out << "Грузоподъемность: " << s.lifting_power << endl;
	out << "Модель: " << s.model << endl;
	out << "Вес: " << s.weight << endl;
	out << "Разновидность: " << s.species << endl;
	out << "Тип: " << s.type << endl;
	return out;
}
