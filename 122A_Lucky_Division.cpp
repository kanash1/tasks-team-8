#include <iostream>

using namespace std;

int main()
{
	int n,d,c=0,e=0;
	cin>>n;

	if(n%4==0||n%7==0||n%47==0||n%74==0||n%447==0||n%477==0){
			c++;
			}
			else{
					while(n!=0){
						d=n%10;
						n=n/10;
						if(d==4||d==7){
							c++;
						}
						else{
							e++;
						}
					}
			}
	if(e>=1){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
	}
	return 0;
}