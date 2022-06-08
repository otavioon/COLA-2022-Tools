#include <bits/stdc++.h>
using namespace std;

int N,K;

bool check(int x,vector<int> d){
  int tmp;
  while (x > 0) {
    tmp = x % 10;
    for (int i = 0; i < K; i++) {
      if (tmp == d.at(i)) return false;
    }
    x /= 10;
  }
  return true;
}

int main() {

  cin >> N >> K;
  std::vector<int> d(K);//キライな数字

  for (int i = 0; i < K; i++) {
    cin >> d.at(i);
  }

  int i = N;
  while (1) {
    if (check(i,d)) {
      cout << i << endl;
      return 0;
    }
    i++;
  }

}
