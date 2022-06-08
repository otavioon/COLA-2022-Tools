#include <bits/stdc++.h>
using namespace std;

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int main()
{
  FIN;
  long n, ans;
  set <long> s;
  set <long>::iterator it, it2;
  cin >> n;
  long arreglo[200005];
  for(long i=0; i<n; i++)
  {
    cin >> arreglo[i];
    s.insert(arreglo[i]);
  }
  for(long i=n-1; i>=0; i--)
  {
    long aux=(long) log2(arreglo[i]);
    long aux2=pow(2,aux);
    if(aux2<arreglo[i]) aux2*=2;
    //cout << "aux = " << aux << " - aux2 = " << aux2 << endl;
    if(s.count(aux2-arreglo[i])!=0)
    {
      it2=s.find(aux2-arreglo[i]); s.erase(it2);
      if(s.count(arreglo[i])!=0)
      {
        it=s.find(arreglo[i]); s.erase(it);
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}