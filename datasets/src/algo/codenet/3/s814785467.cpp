#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#include <math.h> // sqrt()
#include <iomanip>
#define rep(i , n) for (int i = 1; i <= (int)(n); i++)
#define repz(i , n) for (int i = 0; i < (int) n; i++)
#define repi(i , r, n) for (int i = r; i <= (int)(n); i++)
#define repd(i , r, n) for (int i = r; i >= (int)(n); i--)


using namespace std;
int main(){
    int n;
    cin >> n;
    int64_t A[n];
    int64_t B[n];
    int64_t C[n];
    repz( i , n) cin >> A[i];
    repz( i , n) cin >> B[i];
    repz( i , n) cin >> C[i];
    sort(A, A + n);
    sort(B, B + n);
    sort(C, C + n);
    int counta = 0;
    int countc = 0;
    int a = 0;
    int c = 0;
    int ans = 0;
    for ( int64_t i : B){
        repi( j , a , n){
            if ( A[j] < i ) counta++;
            else{
                a = j ;
                break;
            }
        }
        repi( k , c , n ){
            if ( C[k] <= i) countc++;
            else{
                c = k;
                break;
            }
        }
        ans += counta * ( n - countc);
    }
    cout << ans << endl;
}
