#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#include <cmath>
#include <cstdlib>
#include <climits>

//#include <stdio.h>
//#include <stdlib.h>
//#include "show_vector.hh"


using namespace std;

#define debug false

int binaries(unsigned int n){
  unsigned int mask = 1;
  unsigned int nn = n;
  int count = 0;
  for(int i = 0; i < 32; i++){
    count += (nn&mask);
    //printf("n&mask : %u&%u\n", n, mask);
    //printf("count : %d\n", count);
    nn = nn >> 1;
  }
  return count;
}

int main(int argc, char *argv[]){

  int N;
  cin >> N;
  int tmp;
  vector<int> odd(0), even(0);
  int odds = 0, evens = 0;
  for(int i = 0; i < N; i++){
    cin >> tmp;
    if((tmp&1) == 1){ // odd
      odd.push_back(tmp);
      odds++;
    }else{
      even.push_back(tmp);
      evens++;
    }
  }

  int count = 0;

  for(int i = 0; i < odds; i++){
    for(int j = 0; j < i; j++){
      if(odd[i] == 0 || odd[j] == 0) continue;

      tmp = odd[i] + odd[j];
      if(binaries((unsigned int)tmp) == 1){
        //printf("binaries(%d) = %d\n", tmp, binaries(tmp) );
        odd[i] = 0;
        odd[j] = 0;
        count++;
      }
      //printf("binaries(%d) = %d\n", tmp, binaries(tmp) );
    }
  }

  for(int i = 0; i < evens; i++){
    for(int j = 0; j < i; j++){
      if(even[i] == 0 || even[j] == 0) continue;

      tmp = even[i] + even[j];
      if(binaries((unsigned int)tmp) == 1){
        //printf("binaries(%d) = %d\n", tmp, binaries(tmp) );
        even[i] = 0;
        even[j] = 0;
        count++;
      }
      //printf("binaries(%d) = %d\n", tmp, binaries(tmp) );
    }
  }

  cout << count << endl;


  return 0;
}
