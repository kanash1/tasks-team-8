#include <iostream>
using namespace std;
 
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
int main()
{
	IOS
	int t,n,k;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		int tmp1 = n % k;
		int tmp2 = k >> 1;
		if(tmp1 <= tmp2)
			cout << n << '\n';
		else
			cout << n - tmp1 + tmp2 << '\n';
	}
	return 0;
}