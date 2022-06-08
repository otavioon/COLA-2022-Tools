#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

  string S;
  cin >> S;
  unsigned long long int K;
  cin >> K;

  unsigned long long int count = 0;
  unsigned long long int count_1 = 0;

  //cout << S[S.length()-1] << endl;
  int length = S.length();

  //char before = S[0];
  bool flg = false;
  for(int i=1;i<length;++i){
    if(flg){
      flg = false;
      continue;
    }
    if(S[i] == S[i-1]){
      count++;
      //cout << S[i] << endl;
      flg = true;
    }
  }

  if (K>=2){

    bool FLG = (S[length-1] == S[0]) && !flg;
    bool flg = FLG;
    if(FLG) count_1++;

    for(int i=1;i<length;++i){
      if(flg){
        flg = false;
        continue;
      }
      if(S[i] == S[i-1]){
        count_1++;
        //cout << S[i] << endl;
        flg = true;
      }
    }
    count_1 *= K-1;
  }

  //if (S[0] == S[1] && FLG) count += 1;

  cout << count + count_1 << endl;

  return 0;
}
