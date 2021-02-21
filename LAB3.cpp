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
	Lifting_transporting_machines(); // ����������� �� ���������
	Lifting_transporting_machines(char* Model, int Lifting_power, int Weight, int Species, int Type); // ����������� � �����������
	~Lifting_transporting_machines();  // ����������
	Lifting_transporting_machines(const Lifting_transporting_machines& s); // ���������� �����������

	void set_machines(); // ��������� ����� ������� ������
	int get_lifting_power() const; // �����, ������� ���������� �������� ���� frequency
	void copy(const Lifting_transporting_machines& s); // ����� ����������� ����� ���� ������� � ������

	Lifting_transporting_machines& operator=(Lifting_transporting_machines& s); // ���������� ��������� ������������ "="
	bool operator>(Lifting_transporting_machines& s); // ���������� ��������� ��������� ������ ">"
	friend ostream& operator<<(ostream& out, const Lifting_transporting_machines& s); // ���������� ��������� ������ "cout << "

};

/* �����-��������� � ���� ����������� ������� */
class matrix {
private:
	const int size = 2; // ������ �������
	Lifting_transporting_machines matrix[2][2]; // ���� �������
public:
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



	system("pause");
	return 0;
}

Lifting_transporting_machines::Lifting_transporting_machines() // ����������� �����������
{
	char Default[] = "default";
	model = new char[strlen(Default) + 1];
	strcpy_s(model, strlen(Default) + 1, Default);

	lifting_power = 0;
	weight = 0;
	species = 0;
	type = 0;
}

Lifting_transporting_machines::Lifting_transporting_machines(char* Model, int Lifting_power, int Weight, int Species, int Type) // ����������� � �����������
{
	model = new char[strlen(Model) + 1];
	strcpy_s(model, strlen(Model) + 1, Model);

	lifting_power = Lifting_power;
	weight = Weight;
	species = Species;
	type = Type;
}

Lifting_transporting_machines::~Lifting_transporting_machines() // ����������
{
	if (model != NULL) delete[] model;
}

Lifting_transporting_machines::Lifting_transporting_machines(const Lifting_transporting_machines& s) // ���������� �����������
{
	copy(s);
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

void Lifting_transporting_machines::copy(const Lifting_transporting_machines& s) // ����� ����������� ����� ���� ������� � ������
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

Lifting_transporting_machines& Lifting_transporting_machines::operator=(Lifting_transporting_machines& s) // ���������� ��������� ������������ "="
{
	if (this != &s) {
		copy(s);
	}
	return *this;
}

bool Lifting_transporting_machines::operator>(Lifting_transporting_machines& s) // ���������� ��������� ��������� ������ ">"
{
	return lifting_power > s.lifting_power;
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
			cout << matrix[i][j];
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
				cout << matrix[i][j];
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
				cout << matrix[i][j];
			}
		}
	}
}

void matrix::sort() // ����������
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

ostream& operator<<(ostream& out, const Lifting_transporting_machines& s) // ���������� ��������� ������ "cout << "
{
	out << "_______________________________________\n";
	out << "����������������: " << s.lifting_power << endl;
	out << "������: " << s.model << endl;
	out << "���: " << s.weight << endl;
	out << "�������������: " << s.species << endl;
	out << "���: " << s.type << endl;
	return out;
}
