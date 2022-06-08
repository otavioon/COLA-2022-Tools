#include <bits/stdc++.h>
using namespace std;

#define ALL(a) begin(a),end(a)
#define COUNTOF(a) (sizeof(a)/sizeof(a[0]))
#define SP << " " <<
#define FMT(a) #a<<":"<<a 
#define FMT2(a,b) #a<<":"<<a<<", "<<#b<<":"<<b 
#define FMT3(a,b,c) #a<<":"<<a<<", "<<#b<<":"<<b<<", "<<#c<<":"<<c 
#define FMT4(a,b,c,d) #a<<":"<<a<<", "<<#b<<":"<<b<<", "<<#c<<":"<<c<<", "<<#d<<":"<<d 
typedef long long ll;
template<class T> istream& operator >> (istream& s, vector<T>& v) {
  for (T& x: v) s >> x;
  return s;
}
inline void Yes(bool f){cout<<(f?"Yes":"No")<<endl;}
inline void YES(bool f){cout<<(f?"YES":"NO")<<endl;}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    //cout<<std::fixed<<std::setprecision(10);

    int A,B; cin >> A>>B;
    
    string ans = A==B?"Draw":(A==1||(B!=1&&A-B>0)?"Alice":"Bob");

    cout << ans << endl;
}
