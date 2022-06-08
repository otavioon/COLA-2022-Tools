#include <bits/stdc++.h>
using namespace std;
bool is_present(int n,set<int> not_allowed)
{
  while(n)
  {
    if(not_allowed.find(n % 10) != not_allowed.end())
      	return true;
    n /= 10;
   	 
  }
  return false;
  
}
int main()
{
  	int n,k,l;
 	cin>>n>>k;
  	set<int> not_allowed;
  	for(int i=0; i<k; i++)
    {
     	 cin>>l;
      	 not_allowed.insert(l);
    }
  	while(1)
    {
     	if(is_present(n,not_allowed))
        {
          n++;
        }
      else
      {
       	cout<<n;
        return 0;
      }
      
    }
  
}