#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, counter;
  vector<int> vec(N);
  counter = 0;
  cin >> N;
  for (int i = 0; i < N; i++){
    int a;
    cin >> a;
    vec.at(i) = a-1;
  }
  for (int i = 0; i < N; i = vec.at(i)){
    counter++;
    if (counter == N){
      counter = -1;
      break;
    }
    else if (vec.at(i) == 1){
      break;
    }
  }
  cout << counter << endl;
}
