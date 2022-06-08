#include <iostream>
#include <bits/stdc++.h>
#define loop(N) for(int i=0;i<N;i++)
#define vi vector<int>
#define vs vector<string>
#define vl vector<long long int>
#define vpi vector<pair<int,int>>
#define msi map<string,int>
#define mil map<int,long long int>
#define lli long long int
#define plli pair<lli,lli>
using namespace std ;
void ps(string i){
    cout << i << endl;
}

template <class T>
void pt(T s){
    cout << s << endl;
}

void pi(int i){
    cout << i << endl;
}

template <class T>
void pv(vector<T> v){
    loop(v.size()){
        pt<T>(v[i]);
    }
}
/*********************************reused****************************/
const int N = 100009;
lli a[N];
lli b[N];
lli c[N];
int main()
{
    int n;
    cin>>n;
    loop(n){
        cin >>a[i];
    }
    loop(n){
        cin >>b[i];
    }
    loop(n){
        cin >>c[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);
    lli ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
                if(a[i]>=b[j])
                    continue;
                for(int k=0;k<n;k++){
                    if(b[j]>=c[k])
                        continue;
                    else{
                        ans+=n-k;
                        break;
                    }
                }
        }
    }
    cout <<ans<<endl;
    return 0;
}

