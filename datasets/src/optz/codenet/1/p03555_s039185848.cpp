#include <bits/stdc++.h>

#define INF 1e9
using namespace std;
typedef long long ll;

int main() {
int a[3],b[3];
for(int i=0;i<3;++i){
cin >> a[i];
}
for (int i=0;i<3; ++i){
cin >> b[i];
}
reverse(b,b+3);
bool Yes = true;
for(int i=0;i<3;++i){
if(a[i]!=b[i]){
Yes = false;
}
}

if(Yes) cout << "YES" << endl;
else cout << "NO" << endl;
}
