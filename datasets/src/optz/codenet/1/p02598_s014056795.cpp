#include <bits/stdc++.h>

using namespace std;
#define  ll long long
#define ld long double
#define f first
#define s second
//#define x real()
//#define y imag()
#define length(a) (hypot((a).imag() , (a).real()))
#define point complex<ld>
#define perp(a) point((-(a).Y,(a).X))
#define dot(a,b) ( (conj(a)*(b)).real() )
#define cross(a,b) ( (conj(a)*(b)).imag() )
#define rotate0(p,ang) (p * exp(point(0,ang)) )

const int N = 5e5+5;

ll n,k,a[N];

bool check(ll mid)
{
    ll kk=k , tmp;
    for(int i=1; i<=n; i++)
    {
        if (a[i] < mid) continue;
        tmp = (a[i]/mid)-1 + (a[i]%mid != 0);
        if (tmp > kk) return 0;
        kk -= tmp;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for(int i=1; i<=n; i++)
        cin >> a[i];

    ll l=1 , h=1e9 , mid , idx=1e9;
    while(l<=h)
    {
        mid = (l+h)/2;
        if (check(mid))
        {
            idx = min(idx , mid);
            h = mid-1;
        }
        else l=mid+1;
    }

    cout << idx << '\n';

    return 0;
}
