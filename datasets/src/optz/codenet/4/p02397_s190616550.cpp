#include <iostream>

 

using namespace std;

 

int main()
{
    int a, b, i;
    for(i=1; i<=3000; i++)
    {
      cin >> a >> b;
      if(a > b)
       { 
         a=a+b;
         b=a-b;
         a=a-b;
       }
    
     if(a==0,b==0)
     break;
       
    cout << a << " " << b << endl;
    }
}
