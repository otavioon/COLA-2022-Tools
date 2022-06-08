//*Here I go out to sea again
//*The sunshine fills my hair
//*And dreams hang in the air

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

int main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string n;
    int a[10]={0},k;
    cin>>n>>k;
    for(int i=0;i<k;i++){
      int in;
      cin>>in;
      a[in]++;
    }
    string ans;
    for(int i=0;i<n.size();i++)
    {
      int temp=n[i]-'0';
      string k=n.substr(0,i+1);
      int x=atoi(k.c_str());
      int y=atoi(ans.c_str());
      for(int j=0;j<10;j++){
        if(a[j]==0 && (j>=temp || x<y)){
          ans+=(j+'0');
          break;
        }
      }
    }
    cout<<ans<<"\n";

    return 0;
}
