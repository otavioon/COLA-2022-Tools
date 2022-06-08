#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    char arr[N];
    cin >> arr;
    int cnt = 0;
    for (int i = 0; i < N; ++i)
    {
        if (arr[i] == 'A' && arr[i + 1] == 'B' && arr[i + 2] == 'C')
        {
            ++cnt;
        }
    }
    cout << cnt << endl;
    return 0;
}