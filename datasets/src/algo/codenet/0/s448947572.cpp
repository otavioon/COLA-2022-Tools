#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define In_The_Name_Of_Allah_The_Merciful ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Alhamdulillah return 0;
#define all(v) v.begin(),v.end()
#define debug(n) cerr << "[" << #n << " = " << n << "]" << endl 

void Suhaib_Sawalha (){

    string s;
    cin >> s;
    ll ans = 0;
    for (int i = 1 ; i < s.size() ; ++i){
        if (s[i] == s[i-1]){
            char c = s[i-1] , c2 = (i == s.size()-1 ? s[0] : s[i+1]);
            if (c2 == 'a')
                swap(c,c2);
            if (c == 'a' && c2 == 'a')
                s[i] = 'b';
            else if (c == 'b' && c2 == 'b')
                s[i] = 'a';
            else if (c == 'a' && c2 == 'b')
                s[i] = 'c';
            else if (c == 'a')
                s[i] = 'b';
            else 
                s[i] = 'a';
            // a ? a --> b
            // b ? b --> a
            // a ? b --> c
            ++ans;
        }
    }

    ll k;
    cin >> k;
    cout << (ll)ans * k;

}

int main(){
                                In_The_Name_Of_Allah_The_Merciful   /* بسم الله الرحمن الرحيم  */
#ifndef ONLINE_JUDGE
    freopen("SuhaibSawalha1.txt","r",stdin);
#endif
//int _;for(cin>>_;_;--_,cout<<'\n')
        Suhaib_Sawalha();
                                         Alhamdulillah                    /* الحمد لله */
}