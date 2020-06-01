#include <cstdio>
long long remains = 1000000007;
int main()
{
    long long a, b, task;
    scanf("%I64d%I64d", &a, &b);
    task = (((((a*(a+1)/2) % remains)*b+a) % remains)*((b*(b-1)/2) % remains)) % remains;
    printf("%I64d\n", task);
    return 0;
}
