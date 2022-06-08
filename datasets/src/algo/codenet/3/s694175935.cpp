#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;
const int N = 1e5+5;
int A[N],B[N],C[N];
long long ans;


int main()
{
    int n;
    //while(scanf("%d",&n) != EOF)
    //{
    scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%d",A+i);
        for(int i=0; i<n; i++)
            scanf("%d",B+i);
        for(int i=0; i<n; i++)
            scanf("%d",C+i);
        ans = 0;
        int pA=0, pC=0;
        sort(A,A+n);
        sort(B,B+n);
        sort(C,C+n);
        for(int i=0; i<n; i++)
        {
            while(pA<n && A[pA]<B[i])
                pA++;
            while(pC<n && C[pC]<=B[i])
                pC++;
            ans += pA * (n-pC);
        }
        cout << ans << endl;
    //}
    return 0;
}
