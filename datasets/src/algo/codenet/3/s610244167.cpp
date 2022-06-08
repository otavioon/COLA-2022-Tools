#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<cstdlib>
#include<stack>
#include<queue>
#include<algorithm>
#include<set>
#include<vector>
#include<cmath>
#include<string>
#include<bitset>
#define lmid l,mid,rt<<1
#define rmid mid+1,r,rt<<1|1
#define ll long long
using namespace std;
int s[100005], t[100005], r[100005];
long long t1[100005], r1[100005];
int main() {
     int n;;
     scanf("%d", &n);
     for (int i = 0; i < n; i++)
          scanf("%d", &s[i]);
     for (int i = 0; i < n; i++)
          scanf("%d", &t[i]);
     for (int i = 0; i < n; i++)
          scanf("%d", &r[i]);
     sort(s, s + n), sort(t, t + n), sort(r, r + n);
     int j = 0;
     for (int i = 0; i < n; i++) {
          while (j < n && s[j] < t[i])j++;
          t1[i] = j;
     }
     j = 0;
     for (int i = 0; i < n; i++) {
          while (j < n && t[j] < r[i])r1[i] += t1[j], j++;
          if (i != 0)r1[i] += r1[i - 1];
     }
     long long sum = 0;
     for (int i = 0; i < n; i++)
          sum += r1[i];
     printf("%lld\n", sum);
     return 0;
}
