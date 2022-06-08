/*

                         YATIN KWATRA                       _03_08_14


Let's Hoop..



                             __oooo
       //  /    o
     / /  |      o
    | /  |__     o
   | |   __/    o
   | |  /  oooo
  | /  |  _______________________
 | |   | |_______________________|
||    |___ \__/\_/\_/\/\/\/\/\/\/
||    |    \ \/\/\/\/\/\/\/\/\/
||    \     \ \/\/\/\/\/\/\/\/
| |    |    |  \/\/\/\/\/\/\/
 | |    |   |   \/\/\/\/\/\/
  | |    \_/    |\/\/\/\/\/|
   \ \     \__  |/\/\/\/\/\|
    |         \
   |           |
   |           |
   |           |
   |           |
    |          |
    |         |
     |________|
     |________|
    ||         |
   | |          |
  |  /          |
 |  /          /
 /\|__________|
|   /       /
|  |       /
| |       |
 \ |      \
  \ \      \
    \ \     |
      \ \    |
        \ \  |_
          \\_/ \
           |    |
           |   /
           |  |
           |_/



HOOPER_4_LYF..

*/

// AC BAKSHI RABBA

// #pragma GCC optimize "trapv"

#include <bits/stdc++.h>
#define ll                      long long
#define ld                      long double
#define ull                     unsigned long long
#define FIO                     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl                    "\n"
#define fo(i,a,b)               for(int i = a; i<=b ; i++)
#define rfo(i,a,b)              for(int i = a; i>=b ; i--)
#define vii                     vector<int>
#define vll                     vector<ll>
#define pq                      priority_queue
#define uom                     unordered_map
#define all(v)                  v.begin(),v.end()
#define mp                      make_pair
#define pb                      push_back
#define pob                     pop_back
#define ff                      first
#define ss                      second
#define pii                     pair<int,int>
#define pll                     pair<long,long>
#define mll                     map<ll,ll>
#define mii                     map<int,int>
#define vvii                    vector<vii>
#define vvll                    vector<vll>
#define mod                     1000000007
#define MIN                     -1e9
#define pi                      3.1415926535897932384626433832795

using namespace std;

void INPUT()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

/*

   -> Check For Overflows
   -> Out of Bounds
   -> Initialisations of global arrays and variables
   -> Read the Question and the sample test cases carefully
   -> Its not Always Complex, Try to simplify
   -> write it down and try to solve
   -> Have Faith in urself and in ur approach
   -> If it seems totally out of reach, switch to next :)
   -> And Come Back later, if possible ..



o- - -  \o          __|
   o/   /|          vv`\
  /|     |              |
   |    / \_            |
  / \   |               |
 /  |                   |


   Thats what I call a Tappu / Blocked_shot / Rejection...


   Time to Code Now.....
*/

const int N = 200005;

vll v(N);
ll k;

bool possible(ll n, ll sz)
{
  ll steps = 0, cuts;

  fo(i, 0, sz - 1)
  {
    if (v[i] < n) continue;

    cuts = (( (v[i] + n - 1) / n) - 1LL);
    steps += cuts;

    if (steps > k) return 0;
  }
  return (steps > k) ? 0 : 1;
}

void solve()
{

  ll n, mx = 0;
  cin >> n >> k;



  fo(i, 0, n - 1) cin >> v[i], mx = max(mx, v[i]);

  // we will binary search for the smallest L that we could get
  // under cuts <= k

  ll ans = mx;

  ll mn = 1, mid;

  while (mn <= mx)
  {
    if (ans < mn) break;
    if (ans == 0) break;

    mid = (mn + mx) / 2LL;

    if (possible(mid, n))
    {
      ans = min(ans, mid);
      mx = mid - 1;
    }
    else mn = mid + 1;
  }

  cout << ans << endl;

}

int main() {

  FIO
  INPUT();

  int t;
  t = 1;
// cin >> t;

  fo(i, 0, t - 1)
  {
    solve();
  }
  return 0;
}
