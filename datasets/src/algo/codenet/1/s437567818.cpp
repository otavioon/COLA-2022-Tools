#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)

int main(){
   int sum = 0;
   rep(i,3){
      rep(j,3){
         int tmp;
         cin >> tmp;
         sum += tmp;
      }
   }
   if (sum%3 == 0) cout << "Yes" << endl;
   else cout << "No" << endl;
   
}

