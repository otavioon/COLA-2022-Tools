#include <bits/stdc++.h>

using namespace std;

#define vll vector<long long>
#define ll long long
#define ld long double
#define pb push_back
#define vi vector<int>
#define vb vector<bool>
#define vd vector<double>
#define vld vector<long double>
#define vs vector<string>
#define MOD 1000000007
#define endl "\n"
#define vc vector<char>
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define RFOR(i,b,a) for (ll i = (b) - 1; i >= (a); i--)
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define SZ(a) int((a).size())
#define pi acos(-1.0)
#define F first
#define S second
#define RESET(a, b) memset(a, b, sizeof(a))
#define INF 1000000000000000000
#define PLL pair<long,long>
#define PI pair<int,int>
/*

,--.  ,--. ,--. ,--.                                            ,---.       ,--. ,--.
|  ,'.|  | `--' |  |,-.  ,--.,--.  ,---.  ,--. ,--.  ,--,--.   |  o ,-.     |  .'   /  ,--,--.  ,---.   ,---.   ,--,--.
|  |' '  | ,--. |     /  |  ||  | (  .-'   \  '  /  ' ,-.  |   .'     /_    |  .   '  ' ,-.  | | .-. | | .-. | ' ,-.  |
|  | `   | |  | |  \  \  '  ''  ' .-'  `)   \   '   \ '-'  |   |  o  .__)   |  |\   \ \ '-'  | | '-' ' | '-' ' \ '-'  |
`--'  `--' `--' `--'`--'  `----'  `----'  .-'  /     `--`--'    `---'       `--' '--'  `--`--' |  |-'  |  |-'   `--`--'
                                          `---'                                                `--'    `--'
*/





using namespace std;

int main() {
/*
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
*/
//    ifstream in("ladder.in");
//    cin.rdbuf(in.rdbuf());
//    ofstream out("ladder.out");
//    cout.rdbuf(out.rdbuf());

     string n;
     char a;
     ll k;
     cin>>n>>k;
     set <char> number;
     FOR(i,0,k){
         cin>>a;
         number.insert(a);
     }
     FOR(i,0,n.size()){
        if(number.find(n[i])== number.end()){
            continue;
        }else {
            n[i]++;
            i--;
        }
     }
     cout<<n<<endl;




    return 0;
}
