#include<iostream>
#include<stdio.h>
//#include <bits/stdc++.h>
#include<vector>
#include<float.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>
#include<cmath>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include <cassert>
#include <cmath>
#include<cstdint>

#define INF 1e9
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int,int>;

vector<int>bitSearch(int bit,int n){
    vector<int>S;
    rep(i,n)if(bit&(1<<i))S.push_back(i);
    return S;
}

int d[5*100000+1];
int main(){
    string s;cin>>s;
    string t,u,v;
    ll k;cin>>k;
    int n = s.size();
    vector<bool>f(n,false);
    char c = s[0];
    rep(i,n){
        if(c != s[i])break;
        t.push_back(c);
        f[i] = true;
    }
    reverse(ALL(s));
    c = s[0];
    rep(i,n){
        if(f[n-i-1])break;
        if(c != s[i])break;
        v.push_back(c);
        f[n-i-1] = true;
    }
    reverse(ALL(s));
    reverse(ALL(v));
    rep(i,n){
        if(f[i])continue;
        u.push_back(s[i]);
    }
    int ts = t.size()/2;
    int us = 0;
    c = u[0];
    int cnt = 1;
    rep(i,u.size()){
        if(i==0)continue;
        if(c != u[i]){
            us += cnt/2;
            c = u[i];
            cnt = 1;
            continue;
        }
        cnt++;
    }
    us += cnt/2;
    cnt = 1;
    c = v[0];
    int vs = 0;
    rep(i,v.size()){
        if(i==0)continue;
        if(c != v[i]){
            vs += cnt/2;
            c = v[i];
            cnt = 1;
            continue;
        }
        cnt++;
    }
    vs += cnt/2;
    string vt = v+t;
    cnt = 1;
    c = vt[0];
    int vts = 0;
    rep(i,vt.size()){
        if(i==0)continue;
        if(c != vt[i]){
            vts += cnt/2;
            c = vt[i];
            cnt = 1;
            continue;
        }
        cnt++;
    }
    vts += cnt/2;
    ll res = ts+us*k+vts*(k-1)+vs;
    cout<<res;
}

