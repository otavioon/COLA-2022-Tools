#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <stdexcept>
#define ll long long
// #include <bits/stdc++.h>
#define req(i,h) for(int i = 0; i < h; i++)

using namespace std;


int main(void) {
    ll n;
    cin >> n;
    ll i = 2;
    while (i < 1e11){
        if (i % 2 == 0 && i % n == 0) {
            cout << i << endl;
            return 0;
        }
    i = i + 2;
 }
}

