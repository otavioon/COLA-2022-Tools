#include <iostream>
#include <stdio.h>
#include <complex.h>
#include <algorithm>
using namespace std;

int main()
{
    long long n, a[200001], ave = 0;
    long long ans = 10000000;

    cin >> n;
    for(int i = 0; i < n; i++){
      cin >> a[i];
      a[i] -= i + 1;
    }

    sort(a, a+n);
    long long b = a[n / 2];
    long long sum = 0;
    for(int j = 0; j < n; j++)
      sum += abs(a[j] - b);

    cout << sum <<endl;

    return 0;
}
