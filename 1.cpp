#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	double x[4], pi = 3.14, y[4], om[4], f_om[4], x2 = pi / 4, L_x2, y_x2, pogr, ocenka, f0, f01,f012,f0123,f123;
	x[0] = 0;
	x[1] = pi / 6;
	x[2] = pi / 3;
	x[3] = pi / 2;
	om[0] = (x[0] - x[1]) * (x[0] - x[2]) * (x[0] - x[3]);
	om[1] = (x[1] - x[0]) * (x[1] - x[2]) * (x[1] - x[3]);
	om[2] = (x[2] - x[0]) * (x[2] - x[1]) * (x[2] - x[3]);
	om[3] = (x[3] - x[0]) * (x[3] - x[1]) * (x[3] - x[2]);
	for (int i = 0; i < 4; i++)
	{
		y[i] = cos(x[i]);
		f_om[i] = y[i] / om[i];
	}
	cout << "Искомый многочлен методом Лагранжа: " << f_om[0] << "(x-pi/6)(x-pi/3)(x-pi/2) +  " << f_om[1] << "x(x-pi/3)(x-pi/2) " << f_om[2] << "x(x-pi/6)(x-pi/2) +" << f_om[3] << "x(x-pi/3)(x-pi/6) " << endl;
	L_x2 = f_om[0]*(x2-pi/6)*(x2-pi/3) * (x2-pi/2) + f_om[1] * x2 * (x2-pi/3) * (x2-pi/2) + f_om[2] * x2 * (x2-pi/6) * (x2-pi/2) + f_om[3] * x2 * (x2-pi/3) * (x2-pi/6);
	y_x2 = cos(x2);
	pogr = abs(L_x2 - y_x2);
	cout << "Значение погрешности: " << pogr << endl;
	ocenka = (pi / 4) * (pi / 4 - pi / 6) * (pi / 4 - pi / 3) * (pi / 4 - pi / 2) / 24;
	cout << "Оценка погрешности " << ocenka << endl;

	f0 = y[0];
	f01 = (y[0] - y[1]) / (x[0] - x[1]);
	f012 = (f01 - (y[1] - y[2]) / (x[1] - x[2])) / (x[0] - x[2]);
	f123 = ((y[1] - y[2]) / (x[1] - x[2])) - ((y[2] - y[3]) / (x[2] - x[3])) / (x[1] - x[3]);
	f0123 = (f012 - f123) / (x[1] - x[3]);
	cout << "Многочлен методом Ньютона: " << "(" << f0 << ")" << " + x" << "(" << f01 << ")" << " + x(x-pi/6)" << "(" << f012 << ")" << " + x(x-pi/6)(x-pi/3)" << "(" << f0123 << ")" << endl;
	double p_x;
	p_x = f0 + x2*f01 + x2*(x2 - pi / 6)*f012 + x2*(x2 - pi / 6)*(x2 - pi / 3)*f0123;
	y_x2 = cos(x2);
	double pogr2;
	pogr2 = abs(p_x - y_x2);
	cout << "Погрешность: " << pogr2 << endl;
	cout << "Оценка погрешности " << ocenka << endl;
}
