#include <iostream>

using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
	IOS
	int n, x, y, c = 0;
	cin >> n >> x >> y;
	string s;
	cin >> s;
	for(int i = n-1; i >(n-1-x); i--){
		if(i==(n-1-y)){
			if(s[i]=='0'){s[i]='1';c++;}
		}
		else if(s[i]=='1'){s[i]='0';c++;}
	}
	cout << c << "\n";
	return 0;
}
