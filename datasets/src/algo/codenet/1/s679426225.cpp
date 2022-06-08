#include<iostream>
#include <stdio.h>
#include<string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdint>
#include <map>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(){

int a,b,c;
cin >> a >> b >> c;
int B = b - a;
int C = c - a;
for(int i = 0; i < 2; i++){
cin >> a >> b >> c;
if(b - a != B || c - a != C) {cout << "No" << endl; return 0;}
 }

cout << "Yes" << endl;

return 0;
}