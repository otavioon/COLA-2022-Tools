#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int M[3][3];
    while(cin >> M[0][0] >> M[0][1] >> M[0][2])
    {
        for(int i = 1; i < 3; i++)
            for(int j = 0; j < 3; j++)
                cin >> M[i][j];

        int found = 0;
        for(int a1 = -100; a1 <= 100 && !found; a1++)
            for(int a2 = -100; a2 <= 100 && !found; a2++)
                for(int a3 = -100; a3 <= 100 && !found; a3++)
                    if(M[0][0] - a1 == M[1][0] - a2 && M[0][0] - a1 == M[2][0] - a3 &&
                       M[0][1] - a1 == M[1][1] - a2 && M[0][1] - a1 == M[2][1] - a3 &&
                       M[0][2] - a1 == M[1][2] - a2 && M[0][2] - a1 == M[2][2] - a3)
                        found = 1;
        cout << (found? "Yes" : "No") << '\n';
    }
    return 0;
} 