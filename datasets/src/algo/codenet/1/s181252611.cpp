#include <iostream>

using namespace std;

int main()
{
    int i, sum;
    int c[9];

    sum = 0;

    for (i = 0; i < 9; i++)
    {
        cin >> c[i];
        sum += c[i];
    }

    if (sum % 3 == 0 &&
        c[0] + c[8] == c[2] + c[6] &&
        c[0] + c[5] + c[7] == c[1] + c[3] + c[8] &&
        c[0] + c[5] + c[7] == c[0] + c[4] + c[8])
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}