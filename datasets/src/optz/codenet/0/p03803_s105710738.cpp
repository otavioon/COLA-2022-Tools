#include <iostream>
using namespace std;
int main()
{
    int A,B;
    cin>>A>>B;
    if (A==1 && B==1)
    {
        cout<<"Draw";
    }
    else if (A!=1 && B!=1 && A>B && 1<=A<=13 && 1<=B<=13)
    {
        cout<<"Alice";
    }
    else if (A!=1 && B!=1 && B>A && 1<=A<=13 && 1<=B<=13)
    {
        cout<<"Bob";
    }
    else if (A==1 && B!=1)
    {
        cout<<"Alice";
    }
    else if (A!=1 && B==1)
    {
        cout<<"Bob";
    }

    return 0;
}