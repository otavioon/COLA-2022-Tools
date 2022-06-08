#include <iostream>
using namespace std;

int main() {
	int N, K; cin >> N >> K;
	int a[10], d;
	for(int i=0; i<10; ++i) a[i]=0;
	for(int i=0; i<K; ++i){
	    cin >> d;
	    ++a[d];
	}
	int min=0;
	while(a[min]) ++min;
	int ndig[6], ld;
	for(d=0; d<6; ++d){
	    if(N>0 && N<10) ld=d;
	    ndig[d]=N%10;
	    N /= 10;
	}
	int p;
	for(p=0; p<=ld || ndig[p]!=0; ++p){
	    if(a[ndig[p]%10]){
	        for(int i=p-1; i>=0; --i) ndig[i]=min;
	        while(a[ndig[p]%10]) ++ndig[p];
	        if(ndig[p]>9) ++ndig[p+1];
	    }
	}
	for(int i=ld; i>=0; --i) cout << ndig[i]%10;
	cout << endl;
	return 0;
}
