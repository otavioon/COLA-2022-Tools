#include <iostream>

 

using namespace std;

 

int main() 
{
    int a , b , g;
  
     for( g=1; g<=3000; g++)
    {
          cin >> a >> b;
    if (a== 0 && b== 0){
    break;
    }
    
    if (a > b)
    {
    a=a+b;
    b=a-b;
    a=a-b;
    }
    cout << a << " " << b << endl;
   
    }

    
    
}
