#include <iostream>
using namespace std;
int const nm = 107;
int v[nm];
int main()
{
    int n , a , suma = 0 , sumb = 0 ;
    for(int i = 1 ; i <= 3 ; ++ i )
        for (int j = 1; j <= 3; ++ j )
    {
            cin >> a;
            suma += a;
    }
    if ( suma % 3 == 0 && suma > 3)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
