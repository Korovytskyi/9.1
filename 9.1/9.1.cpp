#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Specialty { ʳ����������, �������������, IT, ��������, ������� };

string strSpecialty[] = { "ʳ����������", "�������������", "IT", "��������" , "��������" };

struct Student
{
	string prizv;
	Specialty specialty;
	short unsigned kurs;
	short unsigned physics;
	short unsigned math;
	short unsigned informatics;
};

void Create(Student* s, const int N);
void Print(Student* s, const int N);

double five(Student* s, const int N);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "ʳ������ ��������: "; cin >> N;
	Student* s = new Student[N];
	Create(s, N);
	Print(s, N);
	cout << "| 5 � Գ���� � ���������� " << fixed << five(s, N) << "|" << endl;

	cout << "================================================================================" << endl;
	delete[] s;
}

void Create(Student* s, const int N)
{
	int kurs, specialty;
	for (int i = 0; i < N; i++)
	{
		cout << "� " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << "  �������: "; getline(cin, s[i].prizv);
		cout << "  ����: "; cin >> s[i].kurs;
		cout << "  ������������ (0- ʳ����������, 1- �������������,2- IT,3- �������� ,4-�������� ): "; cin >> specialty;
		s[i].specialty = (Specialty)specialty;
		cout << "  ������ � ������: "; cin >> s[i].physics;
		cout << "  ������ � ����������: "; cin >> s[i].math;
		cout << "  ������ � �����������: "; cin >> s[i].informatics;
	}
}

void Print(Student* s, const int N)
{
	cout << "================================================================================"
		<< endl;
	cout << "| �  | �������     | ���� | ������������ | Գ���� | ���������� | ����������� |"
		<< endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " "
			<< "| " << setw(13) << left << s[i].prizv
			<< "| " << setw(3) << right << s[i].kurs << "  "
			<< "| " << setw(8) << right << strSpecialty[s[i].specialty] << "      "
			<< "| " << setw(4) << right << s[i].physics << "   "
			<< "| " << setw(6) << right << s[i].math << "      "
			<< "| " << setw(6) << right << s[i].informatics << "     |" << endl;
	}
	cout << "================================================================================" << endl;
}



double five(Student* s, const int N)
{
	int k = 0;
	for (int i = 0; i < N; i++)
		if (s[i].physics == 5 || s[i].math == 5)
		{
			k++;
			cout << setw(3) << right << k
				<< " " << s[i].prizv << endl;
			return 0;
		}
}


