#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100+10;

int n;
int b[maxn];
int kq;

int main(){
  scanf("%d",&n);
  for(int i=1;i<=n-1;i++) scanf("%d",&b[i]);
  kq=b[1];
  for(int i=2;i<=n-1;i++)
    kq=kq+min(b[i-1],b[i]);
  kq=kq+b[n-1];
  cout<<kq<<endl;
}
