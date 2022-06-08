#include <bits/stdc++.h>
using namespace std;

int main()
{
   long long n, j, i, s=0;
   
   for(i=1; i<=3; i++)
      for(j=1; j<=3; j++)
	  {
	  	  cin >> n;
	  	  s = s + n; 
	  }
   
   if(s%3==0) 
     cout << "Yes";
   else
     cout << "No";
   return 0;
}