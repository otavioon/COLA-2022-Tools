#include<stdio.h>
#include<cstdio>
#include<string>
#include<map>
using namespace std;

int main() {
  int res = 0;
  for (int i=0 ; i<9 ; i++ ) {
    int num;
    scanf("%d", &num);
    res += num;
  }
  if (res % 3 == 0 && res <= 300) printf("Yes\n");
  else printf("No\n");
}