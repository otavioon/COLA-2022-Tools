#include<bits/stdc++.h>

using namespace std;


typedef long long ll;

int main()
{
    int n;
    cin>>n;
    int d;
    cin>>d;
    d=d*2;
    d++;
    d=n/d;
    if(n%d!=0)d++;
    cout<<d<<endl;
}
