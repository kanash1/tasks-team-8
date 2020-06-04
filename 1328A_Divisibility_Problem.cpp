#include<stdio.h>
int main()
{
    int t,
        num,
        k;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++)
    {
        scanf("%d%d",&num,&k);
        printf("%d\n",(k-num%k)%k);
    }
    return 0;
}
