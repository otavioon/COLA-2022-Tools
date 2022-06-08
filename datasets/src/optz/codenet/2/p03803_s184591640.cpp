#include<bits/stdc++.h>
using namespace std;
     
     
typedef long long ll;
typedef vector <int> vi;
typedef pair <int,int> pi;
typedef tuple <int,int,int> ti;

#define forn(i,a,n) for(int i = a; i < n ; i++)
#define mem(str,a) memset(str, a, sizeof(str));
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(nullptr)
const int MOD = 1e9+7, N = 1e7 + 10, E = 1e-9;
/*
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
//vector <int> show;
//for (auto x : show)
//   cout << x << " ";
getline(cin,s);


*/

int main() {
    int a,b;
    cin >> a >> b;
    if(a == 1 || b == 1) {
        if(a > b)
            cout << "Bob" << endl;
        else if(a < b)
            cout << "Alice" << endl;
        else
            cout << "Draw" << endl;
    }
    else{
        if(a > b)
            cout << "Alice" << endl;
        else if(a<b)
            cout << "Bob" << endl;
        else
            cout << "Draw" << endl;
    }
    return 0;
}
