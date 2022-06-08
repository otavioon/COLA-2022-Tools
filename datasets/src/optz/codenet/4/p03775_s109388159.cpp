#include <iostream>
#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>
#include <math.h>
#include <iomanip>      // std::setprecision
#include <algorithm>
using namespace std;
int main(void){
    long long x;
    cin >> x;
    long long h;
    h = ceil(sqrt(x));
    while(x % h != 0){
        h --;
    }
    long long ha = x/h;
    h = floor(log10(h)) + 1;
    ha = floor(log10(h)) + 1;
    cout << max(h,ha);
    // Here your code !
    
}
