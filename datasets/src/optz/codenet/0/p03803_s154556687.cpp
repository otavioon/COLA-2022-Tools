#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
  int a,b;
  cin >> a  >> b;
  if(a==1 && b==13)cout << "Alice" << endl;
  else if(a==13 && b==1)cout << "Bob" << endl;
  else if(a>b)cout << "Alice" << endl;
  else if(b>a)cout << "Bob" << endl;
  else cout << "Draw" << endl;
  
}