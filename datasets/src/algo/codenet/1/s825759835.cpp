#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

// template from zscoder

int s[3];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a[3][3];

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
            if(i==j)s[0] += a[i][j];
        }
    }
    s[1] = a[0][1]+a[1][2]+a[2][0];
    s[2] = a[0][2]+a[1][0]+a[2][1];
    if(s[0]==s[1]&&s[1]==s[2]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
