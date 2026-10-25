#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

	int Method = 0, Mode = 0;
	string line;
	double x, eps, y;
	int k;

	cout << "Выберите метод вычисления: \n" <<
		"1. С заданной погрешностью eps \n" <<
		"2. С заданным числом k первых членов ряда \n" <<
		"3. По аналитической формуле f(x), используя математические функции библиотек с++\n" <<
		"\nМетод: ";

	while (getline(cin, line))
	{
		stringstream ss(line);

		if (ss >> Method)
		{
			if (ss.eof())
			{
				break;
			}
		}
		cout << "\nОшибка ввода!" << endl;
		cout << "\nМетод: ";
	}

	cout << "Выберите режим отображения чисел с плавающей точкой: \n" <<
		"1. Вывести целиком \n" <<
		"2. Фиксированное число цыфр после запятой \n" <<
		"\nРежим: ";

	while (getline(cin, line))
	{
		stringstream ss(line);

		if (ss >> Mode)
		{
			if (ss.eof())
			{
				break;
			}
		}
		cout << "\nОшибка ввода!" << endl;
		cout << "\nРежим: ";
	}

	cout << "Введите Х: \n";
	
	while (getline(cin, line))
	{
		stringstream ss(line);

		if (ss >> x)
		{
			if (ss.eof())
			{
				break;
			}
		}
		cout << "\nОшибка ввода!" << endl;
		cout << "\nВведите Х: ";
	}

	switch (Method)
	{
	case 1:
		cout << "Введите eps: \n";

		while (getline(cin, line))
		{
			stringstream ss(line);

			if (ss >> eps)
			{
				if (ss.eof())
				{
					break;
				}
			}
			cout << "\nОшибка ввода!" << endl;
			cout << "\nВведите погрешность eps: ";
		}
		
		double u = x;
		int n = 1;
		while (fabs(u) > eps) {
			y += u;
			u *= (x * x * (2.0 * n - 1) * (2.0 * n - 1)) / ((2.0 * n) * (2.0 * n + 1.0));
			n++;
		}
			break;

	case 2:
		cout << "Введите число чисел ряда k: \n";

		while (getline(cin, line))
		{
			stringstream ss(line);

			if (ss >> k)
			{
				if (ss.eof())
				{
					break;
				}
			}
			cout << "\nОшибка ввода!" << endl;
			cout << "\nВведите погрешность eps: ";
		}
		
		double u = x;
		for (int n = 1; n <= k; ++n) {
			y += u;
			u *= (x * x * (2.0 * n - 1) * (2.0 * n - 1)) / ((2.0 * n) * (2.0 * n + 1.0));
		}
			break;

	case 3:
		cout << "Метод 3";
		y = asin(x);
		break;

	default:
		break;
	}

	switch (Mode)
	{
	case 1:
		cout << "Режим 1";
		cout << defaultfloat << setprecision(6) << y << '\n'; // В скобках указать число цыфр до запятой
		break;

	case 2:
		cout << "Режим 2";
		cout << fixed << setprecision(Mode) << y << '\n'; // В скобках указать число цыфр после запятой
		break;

	default:
		break;
	}
}
