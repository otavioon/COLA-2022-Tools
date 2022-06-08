#include <bits/stdc++.h>
using namespace std;

using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)

int main()
{
    int n,k;
    cin >> n>>k;
    vector<int> d(10);
    int min_d = 10,max_d=0,min_d_not_zero=10;
    REP(i, k) {
        int x;
        cin >> x;
        d[x] = 1;
    }
    string ans="";

    REP(i,10){
        //cout << d[i] << " ";
        int x = d[i];
        if(x==0){
            min_d = min(min_d, i);
            if(i!=0)
            min_d_not_zero = min(min_d_not_zero, i);
            max_d = max(max_d, i);
        }
    }
    //cout << min_d_not_zero<<"\n";
    int N = n;
    int end = 0;
    IREP(i,4){
        int x = pow(10, i);
        if(N<x)
            continue;
        int num = n / x;
        n = n - num * x;
        //cout << num<<" "<<x<< "\n";
        if(num==0){
            ans += to_string(min_d);
            continue;
        }
        REP(j,10){
            if (d[j]==1&&j == 9)
            {
                //cout << "aaa" << "\n";
                ans += to_string(min_d_not_zero);
                REP(aaa, i + 1)
                {
                    ans += to_string(min_d);
                }
                end++;
                break;
                //ans += x * 10 * min_d;
            }
            if(d[j]==1)
                continue;
            if(j==num){
                //次の桁を見る
                ans +=  to_string(num);
                break;
            }
            if (j > num)
            {
                ans += to_string(j);
                REP(aaa,i){
                    ans += to_string(min_d);
                }
                //残りは一番小さい桁で埋める
                end++;
                break;
            }
            
        }
        if(end)
            break;
    }

    cout << ans <<"\n";

    return 0;
}