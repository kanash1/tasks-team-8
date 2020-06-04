#include <iostream>
#include <math.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n,	// край стола по оси OX
	m, 	// край стола по оси OY
	x, 	// координата шара на оси OX
	y, 	// координата шара на оси OY
	vx, // направление движения шара вдоль оси OX
	vy;	// направление движения шара вдоль оси OY

// расширенный алгоритм Евклида
int gcd (int a, int b, long long *x, long long *y) {
	if (a == 0) {
		*x = 0; *y = 1;
		return b;
	}
	long long x1, y1;
	int d = gcd (b%a, a, &x1, &y1);
	*x = y1 - (b / a) * x1;
	*y = x1;
	return d;
}

int main() {
	IOS	// ускорение
	cin >> n >> m >> x >> y >> vx >> vy;

	// проверка на движения под углом 90° вдоль OY 
	if(vx == 0) {
		// проверка попадания в лунки
		// с координатами (0;m) и (0;0)
		if(x == 0)
		{
			if(vy == 1) {
				cout << "0 " << m;
				return 0;
			}
			else {
				cout << "0 0";
				return 0;
			}
		}

		// проверка попадания в лунки
		// с координатами (n;m) и (n;0)
		if(x == n)
		{
			if(vy == 1) {
				cout << n << m;
				return 0;
			}
			else {
				cout << n << " 0";
				return 0;
			}
		}

		// если ничего не подошло
		cout << "-1";
		return 0;
	}

	// проверка на движения под углом 90° вдоль OX 
	if(vy == 0) {
		// проверка попадания в лунки
		// с координатами (n;0) и (0;0)
		if(y == 0)
		{
			if(vx == 1) {
				cout << n << " 0";
				return 0;
			}
			else {
				cout << "0 0";
				return 0;
			}
		}

		// проверка попадания в лунки
		// с координатами (n;m) и (0;m)
		if(y == m)
		{
			if(vy == 1) {
				cout << n << m;
				return 0;
			}
			else {
				cout << "0 " << m;
				return 0;
			}
		}

		// если ничего не подошло
		cout << "-1";
		return 0;
	}

	bool x_rotation = false,	// наличие поворота поля по ОX
		 y_rotation = false;	// наличие поворота поля по OY

	// если шар двигается в отрицательном
	// направлении по OX, то поворачиваем поле
	if(vx == -1) {
		x_rotation = true;
		x = n - x;
	}

	// если шар двигается в отрицательном
	// направлении по OY, то поворачиваем поле
	if(vy == -1) {
		y_rotation = true;
		y = m - y;
	}

	// из уравнения прямой
	// x - c = y выражаем с
	int c = x - y;

	// попробуем решить диофантово уравнение вида:
	// a*n+b*m=c
	long long a, b;
	int g = gcd(n, m, &a, &b);

	// если c mod НОД(a,b) ≠ 0, то решений нет,
	// следовательно движение шара зациклится
	if(c % g) {
		cout << "-1";
		return 0;
	}

	// найдем одно из решений уравнения
	int tmp = c / g;
	a = a * tmp;
	b = b * tmp;

	// найдем наименьшее ненулевое решение на положительных полуосях
	tmp = m / g;
	a = (a % tmp + tmp + tmp - 1) % tmp + 1;
	b = (c - a * n) / m;

	// в завимости от значений a и b и наличия поворота
	// найдем координаты лунки
	if(((a & 1) && x_rotation) || (!(a & 1) && !x_rotation))
		cout << "0 ";
    else
    	cout << n << ' ';

    if(((b & 1) && y_rotation) || (!(b & 1) && !y_rotation))
    	cout << "0 ";
    else
    	cout << m << ' ';

    return 0;
}
