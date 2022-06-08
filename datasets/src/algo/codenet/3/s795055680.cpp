#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e5+5;
int a[N],b[N],c[N];
int n;

//顺序查找
int getRes_seq(int);
//二分查找
int getRes_bin(int);

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    for(int i=0;i<n;i++)
        cin>>c[i];
    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);
    int s=0;
    for(int i=0;i<n;i++){
        s+=getRes_seq(a[i]);
    }
    cout<<s<<endl;
    return 0;
}

int getRes_seq(int x)
{
    int s=0;
    for(int i=0;i<n;i++){
        if(b[i]>x){
            for(int j=0;j<n;j++){
                if(c[j]>b[i]){
                    s+=n-j;
                    break;
                }
            }
        }
    }
    return s;
}
