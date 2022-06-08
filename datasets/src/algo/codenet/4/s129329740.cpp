/*Always success does not build on success,success build on failure and hardwork*/
#include <bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define vec         vector<int>
#define map         map<int,int>
#define scn(t)      scanf("%d",&t);
#define lscn(t)      scanf("%lld",&t);
#define mod         1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define endl        "\n"
using namespace std;
const int N=1e5+5;
int main()
{
      int n;
      scn(n);

      int k;
      scn(k);

      set<int> s;

      for(int i=0;i<10;i++)
      {
          s.insert(i);
      }

      for(int i=0;i<k;i++)
      {
          int a;
          scn(a);

          s.erase(a);
      }

      

      while(1)
      {
          bool cp=1;

          int check=n;

          while(check)
          {
              if(s.find(check%10)==s.end())
              {
                  cp=0;
                  break;
              }
              check/=10;
          }

          if(cp)
          {
              cout<<n<<endl;
              return 0;
          }

          n++;
      }
}

