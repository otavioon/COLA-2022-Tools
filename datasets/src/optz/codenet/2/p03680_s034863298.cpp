#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define MN 100009

int N;
int a[MN];
int b[MN];

int main(){
  std::cin >> N;
  for( int i = 1; i <= N; i++ ){
	std::cin >> a[i];
	b[i] = -1;
  }
  int i = 1;
  b[i] = 0;
  do{
	b[a[i]] = b[i] + 1;
	i = a[i];
  }while( b[a[i]] < 0 );
  std::cout << b[2] << std::endl;
  return 0;
}