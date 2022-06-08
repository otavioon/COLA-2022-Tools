#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset> //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip> //do setprecision
#include <ctime>
#include <complex>
using namespace std;

int main(void){
  int c[3][3];
  for (int i = 0; i < 3; ++i){
    for (int j = 0; j < 3; ++j){
      scanf("%d",&c[i][j]);
    }
  }
  if(((c[0][1]-c[0][0])==(c[1][1]-c[1][0])) && ((c[0][1]-c[0][0])==(c[2][1]-c[2][0]) && (c[0][2]-c[0][1])==(c[1][2]-c[1][1])) && ((c[0][2]-c[0][1])==(c[2][2]-c[2][1]) ) ){
    printf("Yes\n");
  }else{
    printf("No\n");
  } 
}