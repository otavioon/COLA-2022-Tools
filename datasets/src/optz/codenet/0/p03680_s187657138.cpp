#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin>>n;
    vector<int> button(n);
    for (int i=0;i<n;i++)
    {
        cin>> button.at(i);
    }
    
    int count=0,p=1;
    do
    {
        count+=1;
        p = button.at(p-1);
    }
    while(p!=1&&p!=2);

    if (p==1)
    cout<<-1<<endl;
    else
    cout<<count<<endl;
}
