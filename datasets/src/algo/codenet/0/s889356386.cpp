#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>

#define REP(i,n) for(int i=0;i<(n);i++)
#define EPS (1e-7)
#define INF (3e9)

using namespace std;
typedef long long int ll;

string s;
ll K;
int main(void){
    cin >> s;
    cin >> K;
    ll len = s.length();
    ll count=0;
    if(s[0] != s[len-1]){
        char n = s[0];
        for (int i=1;i<len;i++){
            if(n==s[i]){
                count++;
                if(i==len-1) break;
                n=s[i+1];
                i++;
            }else n=s[i];
        }
        cout << K*count << endl;
    }else{
        ll st=0, en=len-1;
        while(s[0] == s[st]) st++;
        while(s[0] == s[en]) en--;
        ll r = st+len-1-en;

        string s1 = s.substr(st, en-st+1);
        char n = s1[0];
        ll len1 = s1.length();
        for (int i=1;i<len1;i++){
            if(n==s1[i]){
                count++;
                if(i==len1-1) break;
                n=s1[i+1];
                i++;
            }else n=s1[i];
        }

        if (st<=en) cout << K*count + st/2 + (len-1-en)/2 + (K-1)*(r/2) << endl;
        else cout << len * K / 2 << endl;

    }

    return 0;
}

