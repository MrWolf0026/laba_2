#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

	int Method = 0, Mode = 0;
	string line;
	double x, eps, y = 0.0, u;
	int k, prec;

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
			if (ss.eof() && (Method >= 1 && Method <= 3))
			{
				break;
			}
		}
		cout << "\nОшибка ввода!" << endl;
		cout << "\nМетод: ";
	}

	cout << "\nВыберите режим отображения чисел с плавающей точкой: \n" <<
		"1. Вывести целиком \n" <<
		"2. Фиксированное число цыфр после запятой \n" <<
		"\nРежим: ";

	while (getline(cin, line))
	{
		stringstream ss(line);

		if (ss >> Mode)
		{
			if (ss.eof() && (Mode >= 1 && Mode <= 2))
			{
				break;
			}
		}
		cout << "\nОшибка ввода!" << endl;
		cout << "\nРежим: ";
	}

	cout << "\nВведите Х (X < 1): ";
	
	while (getline(cin, line))
	{
		stringstream ss(line);

		if (ss >> x)
		{
			if (ss.eof())
			{
				if (fabs(x) < 1)
				{
					u = x;
					break;
				}
			}
		}
		cout << "\nОшибка! Модуль X должен быть меньше 1." << endl;
		cout << "\nВведите Х (X < 1): ";
	}

	switch (Method)
	{
	case 1: 
		{
			cout << "\nВведите eps (eps > 0): ";

			while (getline(cin, line))
			{
				stringstream ss(line);

				if (ss >> eps)
				{
					if (ss.eof())
					{
						if (eps > 0)
						{
							break;
						}
					}
				}
				cout << "\nОшибка ввода!" << endl;
				cout << "\nВведите погрешность eps: ";
			}

			int n = 1;
			while (fabs(u) > eps) {
				y += u;
				u *= (x * x * (2.0 * n - 1) * (2.0 * n - 1)) / ((2.0 * n) * (2.0 * n + 1.0));
				n++;
			}
			break;
		}

	case 2: 
		{
			cout << "\nВведите число чисел ряда k (k >= 1): ";

			while (getline(cin, line))
			{
				stringstream ss(line);

				if (ss >> k)
				{
					if (ss.eof() && k > 0)
					{
						break;
					}
				}
				cout << "\nОшибка ввода!" << endl;
				cout << "\nВведите число ряда k (k >= 1): ";
			}
			for (int n = 1; n <= k; ++n) {
				y += u;
				u *= (x * x * (2.0 * n - 1) * (2.0 * n - 1)) / ((2.0 * n) * (2.0 * n + 1.0));
			}
			break;
		}
		

	case 3:
		{
			y = asin(x);
			break;
		}

	default:
		break;
	}

	switch (Mode)
	{
	case 1:
		cout << "\nY = " << defaultfloat << setprecision(17) << y << '\n'; // Общее колличесвто цифр
		break;

	case 2:
		cout << "\nВведите количество знаков после запятой: ";

		while (getline(cin, line))
		{
			stringstream ss(line);

			if (ss >> prec)
			{
				if (ss.eof() && prec >= 0)
				{
					break;
				}
			}
			cout << "\nОшибка ввода!" << endl;
			cout << "\nВведите количество знаков после запятой: ";
		}

		cout << "\nY = " << fixed << setprecision(prec) << y << '\n'; // В скобках указать число цыфр после запятой
		break;

	default:
		break;
	}
}
