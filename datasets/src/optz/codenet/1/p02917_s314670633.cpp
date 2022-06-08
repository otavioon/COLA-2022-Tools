#define _GLIBCXX_DEBUG
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <chrono>
#include <stack>
#include <string>
#include <bitset>
#include <unordered_map>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <cassert>
#include <tuple>
#include <iomanip>
#include <random>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define in insert
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = 1e9 + 5;
void solve(){
    int n;
    cin >> n;
    vi b(n-1);
    for(int i = 0; i < n-1; i++) cin >> b[i];
    int sum = b[n-2];
    for(int i = n - 2; i > 0; i--){
        if(b[i] <= b[i-1]) sum += b[i];
        else sum += b[i-1];
    }
    cout << sum + b[0];
}
int main(){
    speed;
    int t = 1;
    //cin >> t;
    while(t--) solve();
}