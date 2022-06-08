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
  int sum=0;
  for(int i=1; i<=9; i++){
    int n;
    std::cin >> n;
    sum+=n;
  }
  if(sum%3==0) std::cout << "Yes" << '\n';
  else std::cout << "No" << '\n';
  return 0;
}