#import<iostream>
using namespace std;

int main(){
  int n;
  std::cin >> n;
  int b[n-1];
  int count = 0;

  for (size_t i = 0; i < n-1; i++) {
    std::cin >> b[i];
    /* code */
  }

  for (size_t i = 0; i < n-1; i++) {
    if (b[i+1] < b[i]) {
      count += b[i+1];
    }
    else {
      count += b[i];
    }
  }

  if (b[1] < b[0]) {
    count += b[1];
  }
  else {
    count += b[0];
  }

  std::cout << count << '\n';
  return 0;
}
