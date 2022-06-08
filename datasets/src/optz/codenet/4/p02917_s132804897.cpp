#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int s = 0;
    int b1 = 0;
    int b2 = 0;

    cin >> b1;
    b2 = b1;
    s += b1;
    for(int i=2; i<=N-1; i++)
    {
        cin >> b2;
        s += min(b1, b2);
        b1 = b2;
    }
    s += b2;

    cout << s << endl;

    return 0;
}