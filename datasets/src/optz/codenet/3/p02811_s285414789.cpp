/*
                                Author: Ankit Kaul
**********************Code Belongs to Respective Author Only************************************
*/
 
/*#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
 
#include <bits/stdc++.h>
 
#define endl       '\n'
#define PI          3.141592653589
#define jaldi       ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define M           1000000007
#define int         long long int
#define inf         INT_MAX
#define pb          emplace_back
#define pf          emplace_front
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define rall(a)     (a).rbegin(),(a).rend()
using namespace std;
 
int gcd(int a,int b) { return b == 0 ? a : gcd(b, a % b); }
int power(int x,int n){
    int result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x) % M;
        x=(x*x)% M;
        n=n/2;
    }
    return result % M;
}
signed main()
{   jaldi
	int k,x;
	cin>>k>>x;
	k*=500;
	if(k<x)
	cout<<"No";
	else
	cout<<"Yes";
}