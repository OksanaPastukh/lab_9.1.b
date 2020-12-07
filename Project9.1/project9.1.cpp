//Lab_9.1(B)
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> // ������������ ����������� ��������
using namespace std;
enum Specialty { ComputerScience, Informatics, Mathematics, Physics, Work};
string specialtyStr[] = { "����'����� �����", "�����������", "�����.�� ������.","Գ���� �� ������.","������� ��������"};
struct Student
{
	string prizv;
	unsigned course;
	Specialty specialty;
	unsigned grades_in_physics;
	unsigned grades_in_mathematics;
	union
	{
		unsigned grades_in_programming;
		unsigned grades_in_numerical_methods;
		unsigned grades_in_pedagogy;
	};
};
void Create(Student* p, const int N);
void Print(Student* p, const int N);
int LineSearch_count(Student* p, const int N);
double LineSearch_proc(Student* p, const int N);
int main()
{ 
	SetConsoleCP(1251); // ������������ ������� win-cp1251 � ���� �����
	SetConsoleOutputCP(1251); // ������������ ������� win-cp1251 � ���� ������

	int N;
	cout << "������ ������� �������� N: "; cin >> N;

	Student* p = new Student[N];
	double proc;
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ���� ����� �� �����" << endl;
		cout << " [3] - ʳ������ ������ � ���������������� �5�, �4�, �3�:" << endl;
		cout << " [4] - ������� ��������, �� �������� � � ������ � � ���������� ������ �4� ��� �5�:" << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(p, N);
			break;
		case 2:
			Print(p, N);
			break;
		case 3:
			cout << "ʳ������ ������ � ���������������� �5�, �4�, �3�:" << LineSearch_count(p, N) << endl;
			break;
		case 4 :
			proc = LineSearch_proc(p, N);
			cout << "������� ��������, �� �������� � � ������ � � ���������� ������ �4� ��� �5�:" << endl;
			cout << proc << "%" << endl;
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;
		}
	} while (menuItem != 0);
	return 0;
}
void Create(Student* p, const int N)
{
	int specialty;
	for (int i = 0; i < N; i++)
	{
		cout << "������� � " << i + 1 << ":" << endl;
		cin.get(); // ������� ����� ��������� � �� ����������� �������
		cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����

		cout << " �������: "; getline(cin, p[i].prizv);
		cout << " ����: "; cin >> p[i].course;
		cout << "  ������������ (0 -����'����� ����� , 1 -�����������, 2 -�����. �� ������., 3 - Գ���� �� ������., 4 - ������� ��������): ";
		cin >> specialty;
		cout << "  ������ � ������: "; cin >> p[i].grades_in_physics;
		cout << "  ������ � ����������: "; cin >> p[i].grades_in_mathematics;
		p[i].specialty = (Specialty)specialty;
		switch (p[i].specialty)
		{
		case ComputerScience:
			cout << "������ � �������������  : "; cin >> p[i].grades_in_programming;
			break;
		case Informatics:
			cout << "������ � ��������� ������  : "; cin >> p[i].grades_in_numerical_methods;
			break;
		case Mathematics:
		case Physics:
		case Work:
			cout << " ������ � ��������� : "; cin >> p[i].grades_in_pedagogy;
			break;
		}
		cout << endl;
	}
}
void Print(Student* p, const int N)
{
	cout << "=================================================================================================================================================="
		<< endl;
	cout << "|�  |�������  |����|C�����������    |O����� � ������|O����� � ����������|O����� � �������������|O����� � ��������� ������|O����� � ���������|"
		<< endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
	cout <<"|" << setw(2) << right << i + 1 << " ";
	cout <<"|" << setw(10) << left << p[i].prizv
	     <<"|" << setw(3) << right << p[i].course << " "
	     <<"|" << setw(17) << left << specialtyStr[p[i].specialty]
	     <<"|" << setw(14) << right << p[i].grades_in_physics << " "
		 <<"|" << setw(18) << right << p[i].grades_in_mathematics << " ";
		switch (p[i].specialty)
		{
		case ComputerScience:
			cout << "| " << setw(20) << setprecision(2) << fixed << right
				<< p[i].grades_in_programming << " |" << setw(27) << right << "|" << setw(20) << right << "|" << endl;
			break;
		case Informatics:
			cout << "|" << setw(23) <<" |" << setw(25)  << setprecision(2) << fixed << right
				<< p[i].grades_in_numerical_methods << " |" << setw(20) << right << "|" << endl;
			break;
		case Mathematics:
		case Physics:
		case Work:
			cout << "| " << setw(23) << "| " << setw(26) << right << "|" << " " << setw(17) << right
				<< p[i].grades_in_pedagogy << " |" << endl;
			break;
		}
	}
	cout << "=================================================================================================================================================="
		<< endl;
	cout << endl;
}
int LineSearch_count(Student* p, const int N)
{
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].specialty == ComputerScience)
		{
			if (p[i].grades_in_programming >= 3 && p[i].grades_in_programming <= 5)
			{
				count++;
			}
		}
	}
	return  count;
}
double LineSearch_proc(Student* p, const int N)
{
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		if ((p[i].grades_in_physics >= 4 && p[i].grades_in_physics <= 5) &&
			(p[i].grades_in_mathematics >= 4 && p[i].grades_in_mathematics <= 5))
		{
			count++;
		}
	}
	return 100.0 * count / N;
}
