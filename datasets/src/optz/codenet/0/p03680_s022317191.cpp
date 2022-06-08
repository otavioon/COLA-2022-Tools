#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
  int a,s,num;
  cin >> a;
  int b[a];
  num = -1;
  for(int i = 0;i<a+1;i++){
    cin >> b[i];
    b[i]--;
  }
  for(int i=0;i<a;i++){
    if(i==0) s = b[0];
      else if(b[s]==1){
      num = i+1;
      break;
    }
    else s = b[s];
  }
  cout << num << endl;
}