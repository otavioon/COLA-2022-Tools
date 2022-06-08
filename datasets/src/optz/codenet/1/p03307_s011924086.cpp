#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <set>
using namespace std;

int main(){
    int n ; cin >> n;
    long long INF = 1ll << 60;

    for ( long long i = n ; i <= INF ; i++){
        if ( i%2 == 0 && i%n == 0 ){ cout << i << endl;break;}
    }
}