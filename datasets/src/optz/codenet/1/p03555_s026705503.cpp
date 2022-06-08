#include <iostream>

using namespace std;

int main()
{
    char a[6];
    for(int x=0;x<6;x++)
        cin >> a[x];
    if(a[0]!=a[5])
    {
        cout << "NO"<<endl;
        exit(0);
    }
    if(a[2]!=a[3])
    {
        cout << "NO"<<endl;
        exit(0);
    }
    if (a[1] != a[4])
    {
        cout << "NO" << endl;
        exit(0);
    }
    cout<<"YES"<<endl;
}