#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
  vector<int> a(2);

  while(cin >> a[0] >> a[1]){
    if(a[0] == 0 && a[1] == 0) break;
    sort(a.begin(), a.end());
    cout << a[0] << " " << a[1] << endl;
  }

  return 0;

}