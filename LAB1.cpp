#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>

using namespace std;

/* ����� ��������-������������ ������ */
class Lifting_transporting_machines {
private:
	int lifting_power; // ����������������
	char* model = NULL; // ������ 
	int weight; // ���
	int species; // �������������
	int type; // ���

public:
	void defconstructor(); // ����������������� �� ���������
	void constructor(char* Model, int Lifting_power, int Weight, int Species, int Type); // ����������������� � �����������
	void Destructor(); // ����������������

	void get_machines() const; // ����� ����� ������� ������
	void set_machines(); // ��������� ����� ������� ������
	int get_lifting_power() const; // �����, ������� ���������� �������� ���� frequency
	Lifting_transporting_machines& copy(const Lifting_transporting_machines& s); // ����� ����������� ����� ���� ������� � ������

};

/* �����-��������� � ���� ����������� ������� */
class matrix {
private:
	const int size = 2; // ������ �������
	Lifting_transporting_machines matrix[2][2]; // ���� �������
public:
	void Dest(); // ���������� ����������
	void set_matrix(); // ���������� �������
	void enter_matrix(); // ��������� ��������� �������
	void get_matrix() const; // ����� ��������� �������
	void search() const; // �����
	void compare() const; // ���������
	void sort(); // ����������
};

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));

	matrix m; // ��������� �������
	m.set_matrix(); // ��������� �������
	m.get_matrix(); // ������� �������
	system("pause");
	system("cls");

	m.enter_matrix(); // ������� ���� ��������� ������ �������
	system("cls");
	m.get_matrix(); // ������� �������
	system("pause");
	system("cls");

	m.search(); // ����� �� ����������������
	system("pause");
	system("cls");

	m.compare(); // ��������� �� ����������������
	system("pause");
	system("cls");

	m.sort(); // ���������� �� ���������������� (�� �������� � ��������)
	m.get_matrix(); // ������� �������

	m.Dest(); // �������� ���������


	system("pause");
	return 0;
}

void Lifting_transporting_machines::defconstructor() //����������������� �� ���������
{
	char Default[] = "default";
	model = new char[strlen(Default) + 1];
	strcpy_s(model, strlen(Default) + 1, Default);

	lifting_power = 0;
	weight = 0;
	species = 0;
	type = 0;
}

void Lifting_transporting_machines::constructor(char* Model, int Lifting_power, int Weight, int Species, int Type) // ����������������� � �����������
{
	model = new char[strlen(Model) + 1];
	strcpy_s(model, strlen(Model) + 1, Model);

	lifting_power = Lifting_power;
	weight = Weight;
	species = Species;
	type = Type;
}

void Lifting_transporting_machines::Destructor() // ����������������
{
	if (model != NULL) delete[] model;
}

void Lifting_transporting_machines::get_machines() const  // ����� ����� ������
{
	cout << "_______________________________________\n";
	cout << "����������������: " << lifting_power << endl;
	cout << "������: " << model << endl;
	cout << "���: " << weight << endl;
	cout << "�������������: " << species << endl;
	cout << "���: " << type << endl;
}

void Lifting_transporting_machines::set_machines()  // ��������� ����� ������
{
	char str[30];
	cout << "������� ������: "; cin >> str;

	if (model != NULL) delete[] model;
	model = new char[strlen(str) + 1];
	strcpy_s(model, strlen(str) + 1, str);

	lifting_power = rand() % 100;
	weight = rand() % 100;
	species = rand() % 100;
	type = rand() % 100;

}

int Lifting_transporting_machines::get_lifting_power() const // �����, ������� ���������� �������� ���� lifting_power
{
	return lifting_power;
}

Lifting_transporting_machines& Lifting_transporting_machines::copy(const Lifting_transporting_machines& s) // ����� ����������� ����� ���� ������� � ������
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

void matrix::Dest() // ���������� ����������
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j].Destructor();
		}
	}
}

void matrix::set_matrix() // ���������� �������
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j].defconstructor();
		}
	}
}

void matrix::enter_matrix() // ��������� ��������� �������
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j].set_machines();
		}
	}
}

void matrix::get_matrix() const // ����� ��������� �������
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j].get_machines();
		}
	}
	cout << "_______________________________________\n";
}

void matrix::search() const // �����
{
	int lifting;
	cout << "�����\n������� ����������������: "; cin >> lifting;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (matrix[i][j].get_lifting_power() == lifting) {
				matrix[i][j].get_machines();
			}
		}
	}
}

void matrix::compare() const // ���������
{
	int lifting;
	cout << "�����\n������� ����������������: "; cin >> lifting;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (matrix[i][j].get_lifting_power() >= lifting) {
				matrix[i][j].get_machines();
			}
		}
	}
}

void matrix::sort() // ����������
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
