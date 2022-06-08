#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b;

  cin >> a >> b;

  if(a == 1 && b != 1)
    {
      cout << "Alice" << endl;
      return 0;
    }
  else if(a != 1 && b == 1)
    {
      cout << "Bob" << endl;
      return 0;
    }
  if(a >= b)
    {
      if(a == b)
	{
	  cout << "Draw" << endl;
	}
      else
	{
	  cout << "Alice" << endl;
	}
    }
  else
    {
      cout << "Bob" << endl;
    }
  return 0;
}
