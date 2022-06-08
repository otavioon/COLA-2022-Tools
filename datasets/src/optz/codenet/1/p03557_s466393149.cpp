#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n], b[n], c[n],counter=0;
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for (int i=0; i<n; i++)
    {
        cin>>b[i];
    }
    for (int i=0; i<n; i++)
    {
        cin>>c[i];
    }
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            for (int k=0; k<n; k++)
            {
                if (c[i]>b[j] && b[j]>a[k])
                {
                    counter++;
                }
            }
        }
    }
    cout<<counter;
    return 0;
}
