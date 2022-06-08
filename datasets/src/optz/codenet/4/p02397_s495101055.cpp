#include <iostream>

 

using namespace std;

 

int main()
{
    int a ,b, i;
    for(i=1; i<=3000; i++)
    {
        cin >> a >> b;
        if(a==0 && b==0)
            break;
            
        if(a > b)
        {
            a = a+b;
            b = a-b;
            a = a-b;
        }
        cout << a << " " << b << endl;
    }
}
