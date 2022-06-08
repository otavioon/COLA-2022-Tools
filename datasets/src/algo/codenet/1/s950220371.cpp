#include "iostream"
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <cctype>
#include <stack>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
using namespace std;
using ll=long long;
#define mod  1000000007

int main(int argc, char const *argv[]) {
  int line1=0,line2=0,line3=0;;
  for(int i=1; i<=3; i++){
    int n;
    std::cin >> n;
    line1+=n;
  }
  for(int i=1; i<=3; i++){
    int n;
    std::cin >> n;
    line2+=n;
  }
  for(int i=1; i<=3; i++){
    int n;
    std::cin >> n;
    line3+=n;
  }
  if(line1==line2 && line2==line3) std::cout << "Yes" << '\n';
  else std::cout << "No" << '\n';
  return 0;
}
