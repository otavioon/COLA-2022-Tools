#define _GLIBCXX_DEBUG
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<string>
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define rep2(i,s,n) for(int i=s;i< (int)n; i++)
#define ll long long 
#define all(v) v.begin(),v.end()

using namespace std;
//下から押さえる
bool isOK(int index, vector<int>& a, int b, int c) {
    if (a[index] > abs(a[b]-a[c])) return true;
    else return false;
}
// 二分探索
int binary_search(vector<int>& a, int b,int c) {
    int left = c; //「index = b+1」が条件を満たすこともあるので、初期値は -1
    int right = (int)a.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()
    /* どんな二分探索でもここの書き方を変えずにできる！ */
    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if (isOK(mid, a , b, c)) right = mid;
        else left = mid;
    }
    /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
    return right;
}


// 上から押さえる
bool isOK2(int index, vector<int>& a, int b, int c) {
    if (a[index] < a[b]+a[c]) return true;
    else return false;
}
// 二分探索
int binary_search2(vector<int>& a, int b,int c) {
    int left = c; //「index = b+1」が条件を満たすこともあるので、初期値は -1
    int right = (int)a.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()
    /* どんな二分探索でもここの書き方を変えずにできる！ */
    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if (isOK2(mid, a , b, c)) left = mid;
        else right = mid;
    }
    /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
    return left;
}


int main(){
  int n; cin >>n;
  vector<int> L(n);
  rep(i,n) cin >>L[i];
  int ans=0;
  sort(all(L));
  rep(i,n-2){
    rep2(j,i+1,n-1){
          ans+=binary_search2(L,i,j)-binary_search(L,i,j)+1;
    }
  }
  cout <<ans<<endl;
}