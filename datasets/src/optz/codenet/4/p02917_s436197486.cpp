#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define MOD ((int)(1e9) + 7)
#define fast cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define filename "lynext"
#define freop freopen(filename ".cik","w",stdout);freopen(filename ".gir","r",stdin)
const int N = ((int)1e5) + 5;
const int M = ((int)1e3) + 5;
typedef long long int lli;

int n;
int arr[N];
int narr[N];
int sum;

int main ()
{
	fast;
	//freop;
  cin >> n;
  for (int i = 1; i <= n - 1; i++)
  {
    cin >> arr[i];
  }
  narr[1] = arr[1];
  narr[2] = arr[1];
  for (int i = 3; i <= n - 1; i++)
  {
    if (narr[i - 1] <= arr[i] && arr[i] <= arr[i - 1])
      narr[i] = arr[i];
    else
      narr[i] = narr[i - 1];
  }
  narr[n] = narr[n - 1];
  if (arr[n - 1] >= narr[n - 1])
    narr[n] = arr[n - 1];

  for (int i = 1; i <= n; i++)
    sum += narr[i];
  // for (int i = 1; i <= n; i++)
  //   cout << narr[i] << " ";
  // cout << "\n" << "SUM : " << sum << "\n";
  cout << sum << "\n";
}
