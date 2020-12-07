//Lab_9.1(B)
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> // забезпечення відображення кирилиці
using namespace std;
enum Specialty { ComputerScience, Informatics, Mathematics, Physics, Work};
string specialtyStr[] = { "Комп'ютерні науки", "Інформатика", "Матем.та економ.","Фізика та інформ.","Трудове навчання"};
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
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

	int N;
	cout << "Введіть кількість студентів N: "; cin >> N;

	Student* p = new Student[N];
	double proc;
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - Кількість оцінок з програмуваннячий «5», «4», «3»:" << endl;
		cout << " [4] - процент студентів, які отримали і з фізики і з математики оцінки «4» або «5»:" << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
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
			cout << "Кількість оцінок з програмуваннячий «5», «4», «3»:" << LineSearch_count(p, N) << endl;
			break;
		case 4 :
			proc = LineSearch_proc(p, N);
			cout << "процент студентів, які отримали і з фізики і з математики оцінки «4» або «5»:" << endl;
			cout << proc << "%" << endl;
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);
	return 0;
}
void Create(Student* p, const int N)
{
	int specialty;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

		cout << " прізвище: "; getline(cin, p[i].prizv);
		cout << " курс: "; cin >> p[i].course;
		cout << "  спеціальність (0 -Комп'ютерні науки , 1 -Інформатика, 2 -Матем. та економ., 3 - Фізика та інформ., 4 - Трудове навчання): ";
		cin >> specialty;
		cout << "  оцінки з фізики: "; cin >> p[i].grades_in_physics;
		cout << "  оцінки з математики: "; cin >> p[i].grades_in_mathematics;
		p[i].specialty = (Specialty)specialty;
		switch (p[i].specialty)
		{
		case ComputerScience:
			cout << "оцінки з програмування  : "; cin >> p[i].grades_in_programming;
			break;
		case Informatics:
			cout << "оцінки з чисельних методів  : "; cin >> p[i].grades_in_numerical_methods;
			break;
		case Mathematics:
		case Physics:
		case Work:
			cout << " оцінки з педагогіки : "; cin >> p[i].grades_in_pedagogy;
			break;
		}
		cout << endl;
	}
}
void Print(Student* p, const int N)
{
	cout << "=================================================================================================================================================="
		<< endl;
	cout << "|№  |Прізвище  |Курс|Cпеціальність    |Oцінки з фізики|Oцінки з математики|Oцінки з програмування|Oцінки з чисельних методів|Oцінки з педагогіки|"
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
