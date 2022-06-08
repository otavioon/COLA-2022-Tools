#define _USE_MATH_DEFINES
#include  <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include<math.h>
#include<iomanip>
#include<stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include <queue>
#include<map>
#include <sstream>
#include<set>
#include<stack>

//#include<bits/stdc++.h>


using namespace std;


int main()
{

    string p;
    long long int n;
    cin >> p >> n;

    long long int ans = 0;

    if (p.size() == 1) {
        cout << n / 2 << endl;
        return 0;
    }
    set<char>f;
    f.insert(p[0]);
    string d = p;
    for (int i = 1; i < p.size(); i++) {
        f.insert(p[i]);
        if (p[i] == p[i - 1]) {
            p[i] = '?';
            ans++;
        }
    }
    

        
        long long int r = n / 2,w;
        w= p.size() * (r) +p.size()/2 * (n % 2) ;
 
        long long int g = 0;
    if (d[0] == p[p.size() - 1]) {
        g++; d[0] = '?';
    }
    for (int i = 1; i < p.size(); i++) {
        if (d[i] == d[i - 1]) {
            d[i] = '?'; g++;
        }
    }
    cout << min(ans+g*(n-1),w) << endl;
    return 0;

}