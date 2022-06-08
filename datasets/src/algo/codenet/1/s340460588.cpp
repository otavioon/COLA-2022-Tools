#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <cfloat>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <set>
#include <map>
using namespace std;

const double PI=acos(-1);

int main(){
    long c, sum = 0;
    for(int i = 0; i < 9; i++){
        cin >> c;
        sum += c;
    }
    if(sum%3 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}