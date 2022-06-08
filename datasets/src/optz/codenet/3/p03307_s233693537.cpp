#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long int abss(long long int x){return x>=0?x:-x;}

int main(){
int n;
long long int sum_a, sum=1000000000000000;
cin >> n;
long long int a[n],bi[n];
for(int i=0;i<n;i++){
cin >> a[i];
bi[i] = a[i] - (i+1);
//cout<<bi[i]<<endl;
}

sort(bi, bi+n);
for(int c=-1;c<=1;c++){
int b=bi[n/2+c];
sum_a = 0;
for(int i=0;i<n;i++) sum_a += abs(a[i]-(b+i+1));
if(sum_a<=sum){sum=sum_a;}
}

cout << sum << "\n";
}