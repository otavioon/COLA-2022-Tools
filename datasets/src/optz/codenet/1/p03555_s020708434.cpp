#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a,b;
    int n=2,c=0;
    cin>>a>>b;
    for(int i=0;i<3;i++){
        if(a[i]==b[n])
            c++;
        n--;
    }
    if(c==3)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}

