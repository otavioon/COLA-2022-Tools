#include <iostream>
using namespace std;

int main() {
  long long N; cin >> N;
  for ( long long i = 1; i <= 10000000000; i++ ) {
    if ( i % 2 == 0 && i % N == 0 ) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
