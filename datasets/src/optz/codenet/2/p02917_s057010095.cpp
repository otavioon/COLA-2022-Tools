#include <bits/stdc++.h>
using namespace  std;

int main()
{
 int n;
 cin>>n;
 vector <int> vec;
 for(int i=0;i<n-1;i++)
 {
     int x;
     cin>>x;
     vec.push_back(x);
 }
 vector <int> ans;
 ans.push_back(vec[0]);
 for(int i=1;i<n-1;i++)
 {
     ans.push_back(min(vec[i],vec[i-1]));
 }
 ans.push_back(vec[n-2]);
 long long sum=0;
 for(auto v:ans)
     sum+=v;
 cout<<sum;
}
