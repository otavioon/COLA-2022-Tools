#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define fx(p) for(int x=0;x<(p);x++)
#define fy(p) for(int y=0;y<(p);y++)
#define fz(p) for(int z=0;z<(p);z++)
#define ce(d) cout<<d<<endl;

int main() {
int N,n;
  int A[100000];
int B[100000];
int C[100000];

cin >> N;
fx(N){
cin >> A[x];
}
fx(N){
cin >> B[x];
}
fx(N){
cin >> C[x];
}

sort(A,A+N);
sort(B,B+N);
sort(C,C+N);

ll ans=0;

fx(N){
fy(N){
fz(N){

if(A[x]<B[y]&&B[y]<C[z]){
ans+=(N-z);
z=N;
}
}
}
}

ce(ans);

}