#include<bits/stdc++.h>

using namespace std;

// Utility
#define rep(i,n) for(int i = 0; i < (n); ++i)

// Sorting
void insertionSort(int n,int*a,int g=1){for(int i=g;i<n;++i){int v=a[i],j=i-g;while(j>=0&&a[j]>v){a[j+g]=a[j];j-=g;}a[j+g]=v;}}
void shellSort(int n,int*a){vector<int>G;for(int h=1;;){if(h>n)break;G.push_back(h);h=3*h+1;}for(int i=G.size()-1;i>=0;--i)insertionSort(n,a,G[i]);}
int bubbleSort(int n,int*a){int s=0,j;bool f=1;for(int i=0;f;++i){f=0;for(j=n-1;j>=i+1;--j){if(a[j]<a[j-1]){swap(a[j],a[j-1]);f=1;s++;}}}return s;}
int selectionSort(int n,int*a){int s=0,j,m;for(int i=0;i<n-1;++i){m=i;for(j=i;j<n;++j)if(a[j]<a[m])m=j;swap(a[i],a[m]);if(i!=m)++s;}return s;}

// Searching
int binarySearch(int n,int*a,int k){int m,l=0,r=n;while(l<r){m=l+(r-l)/2;if(k<a[m])r=m;else if(a[m]<k)l=m+1;else return m;}return-1;}

// Mathematics
int gcd(int a,int b){!b?a:gcd(b,a%b);}
int lcm(int a,int b){return a/gcd(a,b)*b;}

// Visualization
void printArray(int n,int*a){for(int i=0;i<n;++i)printf(i>0?" %d":"%d",a[i]);printf("\n");}

int main(){
	int k,x; cin >> k >> x;
	cout << (k*500>=x ? "Yes" : "No") << endl;
}