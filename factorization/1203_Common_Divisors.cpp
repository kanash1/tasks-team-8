#include <stdio.h>
using namespace std;
 
int n;				// количетсво элементов "массива"
long long big_gcd,		// НОД элементов
		  a,		// элемент
		  res,		// количетсво общих делителей
		  i;		// параметр цикла
 
long long gcd (long long x, long long y) {
	return y ? gcd (y, x % y) : x;
}
 
int main()
{
	scanf("%d", &n);
	while(n--) {
		scanf("%lld", &a);
		big_gcd = gcd(a, big_gcd);
	}
	for(i = 1; i * i < big_gcd; i++)
		if(!(big_gcd % i))
			res += 2;
	if(i * i == big_gcd)
		res++;
	printf("%lld", res);
	return 0;
}
