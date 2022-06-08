#include<cstdio>
#include<set>

using namespace std;

set<int> s;

int check(int n){
	while(n > 0){
		if(s.find(n % 10) != s.end()) return 0;
		n /= 10;
	}
	return 1;
}

int main(){
	int n, k; scanf("%d %d", &n, &k);
	for(int i = 0; i < k; i++){
		int d; scanf("%d", &d);
		s.insert(d);
	}
	for(; !check(n); n++);
	printf("%d\n", n);
	return 0;
}