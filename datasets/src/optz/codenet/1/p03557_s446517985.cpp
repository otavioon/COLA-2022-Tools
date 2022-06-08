#include<bits/stdc++.h>

using namespace std;

#define inputInt(a) scanf("%d", &a)
#define inputStr(a) getline(cin, a)
#define inputLong(a) scanf("%lld", &a)
#define clr(a) memset(a, 0, sizeof(a))
#define printn(a) cout<<a<<"\n"
#define print(a) cout<<a

long long alter[3][100010];

int main()
{
    long long N;
    long long num;
    int a[100010];
    int b[100010];
    cin>>N;

    for(int i = 0; i<3 ; i++)
    {
        for(int j =0; j<N; j++)
        {
            inputLong(num);
            alter[i][j] = num;
        }
    }
/*
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<N; j++)
            printf("%lld ",alter[i][j]);
        printf("\n");
    }
*/
    bool first = true;
    bool second = true;
    for(int i=0; i<N; i++)
    {
        int cnt = 0;
        int cnt2 = 0;
        for(int j=0; j<N; j++)
        {
            if(alter[0][i] < alter[1][j])
                cnt++;

            if(alter[1][i] < alter[2][j])
                cnt2++;
        }
        a[i] = cnt;
        b[i] = cnt2;
    }

    long long result =0;

    int res[100010];
    res[0] = b[0];

    for(int i=1; i<N; i++)
        res[i]= res[i-1]+b[i];


    for(int i=0; i<N; i++)
        result += res[a[i]-1];

    printn(result);

    return 0;

}
