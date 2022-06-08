#include <iostream>
#include <vector>
#define rep(i, n)   for(int i = 0; i < (n); i++)
using namespace std;
typedef long long int ll;

int main(){
    /*input*/
    char c[2][3];
    rep(i, 2)	rep(j, 3)   cin >> c[i][j];
    /*calculation*/
    /*output*/
    if(c[0][0] == c[1][2] && c[0][1] == c[1][1] && c[0][2] == c[1][0]){
	cout << "YES" << endl;
    }else{
	cout << "NO" << endl;
    }
}
