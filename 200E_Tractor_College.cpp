#include<bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n,
    c,
    b3,
    b4,
    b5,
    ans = 1e9 + 7,
    t,
    x,
    a,
    b,
    cc;
main()
{
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if(x == 3)
        {
            b3++;
        }
        if(x == 4)
        {
            b4++;
        }
        if(x == 5)
        {
            b5++;
        }
    }
    for (int i = c / n; i >= 0; i--)
    {
        for (int j = (c - i * b3) / (b4 + b5); j >= i; j--)
        {
            t = (c - i * b3  - j * b4) / b5;
            if (t * b5 - j * b4 >= ans)
            {
                break;
            }
            if (i * b3 + j * b4 + t * b5 == c &&  j <= t)
            {
                if (ans > abs(i * b3 - j * b4) + abs(j * b4 - t * b5))
                {
                    a = i;
                    b = j;
                    cc = t;
                    ans = abs(i * b3 - j * b4) + abs(j * b4 - t * b5);
                }
            }
        }
    }
    if (ans == 1e9 + 7)
    {
        cout << "-1";
    }
    else
    {
        cout << a << ' ' << b << ' ' << cc;
    }
}
