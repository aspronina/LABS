#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>

using namespace std;

/* Êëàññ ïîäúåìíî-òðàíñïîðòíûå ìàøèíû */
class Lifting_transporting_machines {
private:
	int lifting_power; // Ãðóçîïîäúåìíîñòü
	char* model = NULL; // Ìîäåëü 
	int weight; // Âåñ
	int species; // Ðàçíîâèäíîñòü
	int type; // Òèï

public:
	void defconstructor(); // Ïñåâäîêîíñòðóêòîð ïî óìîë÷àíèþ
	void constructor(char* Model, int Lifting_power, int Weight, int Species, int Type); // Ïñåâäîêîíñòðóêòîð ñ ïàðàìåòðàìè
	void Destructor(); // Ïñåâäîäåñòðóêòîð

	void get_machines() const; // Âûâîä ïîëåé îáúåêòà êëàññà
	void set_machines(); // Èçìåíåíèå ïîëåé îáúåêòà êëàññà
	int get_lifting_power() const; // Ìåòîä, êîòîðûé âîçâðàùàåò çíà÷åíèå ïîëÿ frequency
	Lifting_transporting_machines& copy(const Lifting_transporting_machines& s); // Ìåòîä êîïèðîâàíèÿ ïîëåé îäíî îáúåêòà â äðóãîé

};

/* Êëàññ-êîíòåéíåð â âèäå ñòàòè÷åñêîé ìàòðèöû */
class matrix {
private:
	const int size = 2; // ðàçìåð ìàòðèöû
	Lifting_transporting_machines matrix[2][2]; // ñàìà ìàòðèöà
public:
	void Dest(); // Äåñòðóêòîð êîíòåéíåðà
	void set_matrix(); // Çàïîëíåíèå ìàòðèöû
	void enter_matrix(); // Èçìåíåíèå ýëåìåíòîâ ìàòðèöû
	void get_matrix() const; // Âûâîä ýëåìåíòîâ ìàòðèöû
	void search() const; // Ïîèñê
	void compare() const; // Ñðàâíåíèå
	void sort(); // Ñîðòèðîâêà
};

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));

	matrix m; // îáúÿâëÿåì ìàòðèöó
	m.set_matrix(); // çàïîëíÿåì ìàòðèöó
	m.get_matrix(); // âûâîäèì ìàòðèöó
	system("pause");
	system("cls");

	m.enter_matrix(); // èçìåíÿì ïîëÿ îáúåêñòàì âíóòðè ìàòðèöû
	system("cls");
	m.get_matrix(); // âûâîäèì ìàòðèöó
	system("pause");
	system("cls");

	m.search(); // ïîèñê ïî ãðóçîïîäúåìíîñòè
	system("pause");
	system("cls");

	m.compare(); // ñðàâíåíèå ïî ãðóçîïîäúåìíîñòè
	system("pause");
	system("cls");

	m.sort(); // ñîðòèðîâêà ïî ãðóçîïîäúåìíîñòè (îò ìåíüøåãî ê áîëüøåìó)
	m.get_matrix(); // âûâîäèì ìàòðèöó

	m.Dest(); // âûçûâàåì äóòðóêòîð


	system("pause");
	return 0;
}

void Lifting_transporting_machines::defconstructor() //Ïñåâäîêîíñòðóêòîð ïî óìîë÷àíèþ
{
	char Default[] = "default";
	model = new char[strlen(Default) + 1];
	strcpy_s(model, strlen(Default) + 1, Default);

	lifting_power = 0;
	weight = 0;
	species = 0;
	type = 0;
}

void Lifting_transporting_machines::constructor(char* Model, int Lifting_power, int Weight, int Species, int Type) // Ïñåâäîêîíñòðóêòîð ñ ïàðàìåòðàìè
{
	model = new char[strlen(Model) + 1];
	strcpy_s(model, strlen(Model) + 1, Model);

	lifting_power = Lifting_power;
	weight = Weight;
	species = Species;
	type = Type;
}

void Lifting_transporting_machines::Destructor() // Ïñåâäîäåñòðóêòîð
{
	if (model != NULL) delete[] model;
}

void Lifting_transporting_machines::get_machines() const  // Âûâîä ïîëåé êëàññà
{
	cout << "_______________________________________\n";
	cout << "Ãðóçîïîäúåìíîñòü: " << lifting_power << endl;
	cout << "Ìîäåëü: " << model << endl;
	cout << "Âåñ: " << weight << endl;
	cout << "Ðàçíîâèäíîñòü: " << species << endl;
	cout << "Òèï: " << type << endl;
}

void Lifting_transporting_machines::set_machines()  // Èçìåíåíèå ïîëåé êëàññà
{
	char str[30];
	cout << "Ââåäèòå ìîäåëü: "; cin >> str;

	if (model != NULL) delete[] model;
	model = new char[strlen(str) + 1];
	strcpy_s(model, strlen(str) + 1, str);

	lifting_power = rand() % 100;
	weight = rand() % 100;
	species = rand() % 100;
	type = rand() % 100;

}

int Lifting_transporting_machines::get_lifting_power() const // Ìåòîä, êîòîðûé âîçâðàùàåò çíà÷åíèå ïîëÿ lifting_power
{
	return lifting_power;
}

Lifting_transporting_machines& Lifting_transporting_machines::copy(const Lifting_transporting_machines& s) // Ìåòîä êîïèðîâàíèÿ ïîëåé îäíî îáúåêòà â äðóãîé
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

void matrix::Dest() // Äåñòðóêòîð êîíòåéíåðà
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j].Destructor();
		}
	}
}

void matrix::set_matrix() // Çàïîëíåíèå ìàòðèöû
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j].defconstructor();
		}
	}
}

void matrix::enter_matrix() // Èçìåíåíèå ýëåìåíòîâ ìàòðèöû
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j].set_machines();
		}
	}
}

void matrix::get_matrix() const // Âûâîä ýëåìåíòîâ ìàòðèöû
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j].get_machines();
		}
	}
	cout << "_______________________________________\n";
}

void matrix::search() const // Ïîèñê
{
	int lifting;
	cout << "ÏÎÈÑÊ\nÂâåäèòå ãðóçîïîäúåìíîñòü: "; cin >> lifting;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (matrix[i][j].get_lifting_power() == lifting) {
				matrix[i][j].get_machines();
			}
		}
	}
}

void matrix::compare() const // Ñðàâíåíèå
{
	int lifting;
	cout << "ÏÎÈÑÊ\nÂâåäèòå ãðóçîïîäúåìíîñòü: "; cin >> lifting;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (matrix[i][j].get_lifting_power() >= lifting) {
				matrix[i][j].get_machines();
			}
		}
	}
}

void matrix::sort() // Ñîðòèðîâêà
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
