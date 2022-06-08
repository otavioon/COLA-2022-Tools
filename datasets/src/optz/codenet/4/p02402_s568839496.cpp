#include <iostream>
using namespace std;
int main()
{
    long long int x, i, n, sum, min, max, input;
   
    cin >> n;
    sum = 0;
    x = 1;
    
    if ( n == 1 )
        {
            cin >> input;
            max = min = sum = input;
        }
    else {    
    for(i=1; i<=n; i++)
    {
        cin >> input;
        sum = sum + input;
        if(input > max)
            max = input;
        if( x == 1 )
            {
                min = input;
                x = x + 1;
            }
        else if(input < min)
            min = input;
    }
    }
    cout << min << " " << max << " " << sum << endl;
    
    return 0;
}
