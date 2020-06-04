#include <iostream>
 
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
int main(){
    IOS
    long long int n, m, i, j, res =0 ;
    cin >> n >> m;
    for(i = 1; i <= m; i++){
        for(j = 1; j <= m; j++){
            if((i * i + j * j)% m == 0 && n - i >= 0 && n - j>=0){
                res += ((n - i)/m + 1) * ((n - j)/m + 1);
            }
        }
    }
    cout << res;
}