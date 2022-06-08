#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
int A[100010],B[100010],C[100010];
ll cnt[100010][4] = {0};
ll ans = 0;

int main()
{
    scanf("%d",&N);
    for(int i = 0; i < N; i++)scanf("%d",A + i);
    for(int i = 0; i < N; i++)scanf("%d",B + i);
    for(int i = 0; i < N; i++)scanf("%d",C + i);

    sort(A,A + N);
    sort(B,B + N);
    sort(C,C + N);

    int now = N - 1;
    ll sum = 0;


    for(int i = 0; i < N; i++)cnt[i][2] = 1;

    for(int i = N - 1; i >= 0; i--)
    {
        while(now != -1 && B[i] < C[now]){sum += cnt[now][2];now--;}
        cnt[i][1] = sum;
    }

    now = N - 1;sum = 0;

    for(int i = N - 1; i >= 0; i--)
    {
        while(now != -1 && A[i] < B[now]){sum += cnt[now][1];now--;}
        cnt[i][0] = sum;
        ans += cnt[i][0];
    }


    printf("%lld\n",ans);
    return 0;
}
