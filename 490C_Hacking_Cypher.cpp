#include <stdio.h>

using namespace std;

int main() {
	int a,	// число делимое
	    b;	// число остаток

	// ввод данных
	scanf("%d%d", &a, &b);

	// если a = b, то решений
	// бесконечное множество
	if (a == b) {
		puts("infinity");
		return 0;
	}
	// если a < 2b, то решений вовсе нет
	else if (a < 2 * b) {
		printf("%d", 0);
		return 0;
	}
	// последний случай, когда a > b
	// в данной ситуации искомое x
	// будет равно количеству делителей
	// разницы a - b больших b
	else {
		int cnt = 0,
			sub = a - b;
		// поиск делителей парами и проверка условий
		for (int i = 1; i * i <= sub; i++) {
			if (!(sub % i) && a % i == b) {
				cnt++;
			}
			if (i * i != sub && a % (sub / i) == b) {
				cnt++;
			}
		}

		// вывод результата
		printf("%d", cnt);
	}

	return 0;
}
