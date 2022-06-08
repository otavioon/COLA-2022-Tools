#include "bits/stdc++.h"
using namespace std;
int main(){
    vector<bool>v(201);
    v[105]=v[135]=v[165]=v[189]=v[195]=1;
    int n;
    cin>>n;
    cout<<accumulate(v.begin(),v.begin()+1+n,0);
}