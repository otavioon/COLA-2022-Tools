#include<iostream>
#include<string>
#include <cmath>
#include<vector>
#include<algorithm>
 
using namespace std;
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(a,b) (a += b,b = a - b,a -= b)
#define ll long long




int main()
{
    int a[100000], b[100000], c[100000];
    int N;
    cin >> N;
    int tmp;
    REP(i, N)cin >> a[i];
    REP(i, N)cin >> b[i];
    REP(i, N)cin >> c[i];

    sort(a, a+N);
    sort(b, b+N);
    sort(c, c+N);
    
    int cnt = 0;

    int i, k;
    REP(j, N)
    {
        i = 0;
        k = 0 ;
        while(a[i] < b[j] && i < N) i++;
        while(b[j] >= c[k] && k < N) k++;
        cnt += i * (N - k);
    }

    cout << cnt << endl;

}