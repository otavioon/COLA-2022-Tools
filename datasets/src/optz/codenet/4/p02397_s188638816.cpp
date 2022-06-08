#include <iostream>

using namespace std;

int main() {
    int i,a,b;
    cin>>a>>b;
    for(i=0;(a!=0 || b!=0);i++)
    {
        if (a >=b)
        {
            a=a+b;
            b=a-b;
            a=a-b;
        }
        cout<<a<<" "<<b<<endl;
        cin>>a>>b;
    }
}
