#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n,k;
    cin>>n>>k;
    int a[k];
    for(int i=0;i<k;i++)
    {
        cin>>a[i];
    }
    sort(a,a+k);
    for(int i=0;i<k;i++)
    {
        if(a[i]!=1)
        {
            cout<<n*1<<endl;
            break;
        }
         else if(a[i]!=2)
        {
            cout<<n*2<<endl;
            break;
        }
         else if(a[i]!=3)
        {
            cout<<n*3<<endl;
            break;
        }
         else if(a[i]!=4)
        {
            cout<<n*4<<endl;
            break;
        }
        else if(a[i]!=5)
        {
            cout<<n*5<<endl;
            break;
        }
        else if(a[i]!=6)
        {
            cout<<n*6<<endl;
            break;
        }
        else if(a[i]!=7)
        {
            cout<<n*7<<endl;
            break;
        }
        else if(a[i]!=8)
        {
            cout<<n*8<<endl;
            break;
        }
         else if(a[i]!=9)
        {
            cout<<n*9<<endl;
            break;
        }

    }

}



