#include <stdio.h>
#include <cmath>
#define N 1000000

using namespace std;

int n,              // количество древних чисел
    k,              // числа k
    m,              // вспомогательная переменная для факторизации
    primeFactor,    // очередной множитель факторизации числа k
    c[N];           // массив древних чисел, c

bool answer;        //результат проверки 

int main(){
    // ввод данных
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++)
        scanf("%d", c + i);

    m = sqrt(k) + 1;

    // факторизауия и полверка условия возможности нахождения x,
    // т.е. проверка c_i mod p^q == 0,
    // где p^q - множиетль факторизации,
    // или же в коде !(c[i] % primeFactor)
    for (int i = 2; i <= m; i++) {
        primeFactor = 1;

        // сокращаем k на его простой множитель,
        // пока это возможно, паралельно выделяя его степень
        while (!(k % i)) {
            k /= i;
            primeFactor *= i;
        }

        // проверка вышеописанного условия
        if(primeFactor != 1) {
            answer = false;

            // при нахождении c[i], удовлетворяющего условию
            // прекращаем работу цикла
            for (int i = 0; i < n && !answer; i++)
                if (!(c[i] % primeFactor))
                    answer = true;
            // если c[i] не был найден выводим ответ
            // и прекращаем работу цикла
            if (!answer) {
                puts("No");
                return 0;
            }
        }
    }

    // повторяем вышесделанное с оставшимся от факторизации k множителем
    answer = false;

    for (int i = 0; i < n && !answer; i++)
        if (!(c[i] % k))
            answer = true;
    if (!answer)
        puts("No");
    else
        puts("Yes");

    return 0;
}
