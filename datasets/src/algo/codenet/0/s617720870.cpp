#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

string v;
ll n, k;

bool isfull(){
  for(int i = 1; i <= n; i++)
    if(v[1] != v[i])
      return 0;
  return 1;
}

int main()
{
  cin >> v >> k;
  n = v.size();
  v = '#' + v;

  if(isfull() == 1)
    cout << 1LL * n * k / 2;
  else{
    if(v[1] != v[n]){
      ll result = 0, sum = 0;
      for(int i = 1;i <= n; i++){
        if(v[i - 1] != v[i]) {
          result += sum / 2;
          sum = 1;
        } else
          sum++;
      }
      result += sum / 2;
      cout << k * result;
    } else {
      ll result = 0, sum = 0;
      ll x = 1, y = n;
      while(v[x] == v[x + 1])
        x++;
      while(v[y - 1] == v[y])
        y--;

      for(int i = x + 1;i < y; i++){
        if(v[i - 1] != v[i]) {
          result += sum / 2;
          sum = 1;
        } else
          sum++;
      }
      result += sum / 2;
      cout << k * result + x / 2 + (n - y + 1) / 2 + (k - 1) * (x + (n - y + 1)) / 2;
    }
  }
  return 0;
}
