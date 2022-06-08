///    *****       *     **    **   *******     *   **    ** //////
///    **         * *    ** *  **      **      * *   **  **  /////////
///    *****     *****   **  * **      **     *****   ****  /////////////
///       **    *******  **   ***  **  **    *******   **   ////////
///    *****   **     ** **    **  ******   **     **  **   /////
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

void solve()
{
  int n,sum=0;
  cin>>n;
  int b[n-1];cin>>b[0];sum+=(2*b[0]);
  for(int i=1;i<n-1;i++)
  {
      cin>>b[i];
      if(b[i-1]>b[i])
      {
          sum-=(b[i-1]-b[i]);
          sum+=(b[i]);
      }
      else
      {
          sum+=b[i];
      }
  }cout<<sum;
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
