#include <iostream>
 
using namespace std;
 
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
int t,s,res;
 
int main()
{
	IOS
	cin >> t;
	while(t--) {
		cin >> s;
		res = s;
		while(s >= 10) {
			res += s/10;
			s = s%10 + s/10;
		}
		cout << res << '\n';
	}
	return 0;
}