#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#include <vector>
#include <numeric>
#include <map>
#include <cmath>
#include <iomanip>
#include <queue>
using ll =long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vs = vector<string>;

int main() {
    int sum = 0;
    int c;
    for(int i=0; i<9; i++){
        cin >> c;
        sum += c;
    }
    if(sum%3 == 0){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
