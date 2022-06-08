#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, k;
double a[MAXN];
bool Check(double x){
	priority_queue<double> p;
	for(int i = 1; i <= n; i++) p.push(a[i]);
	for(int i = 1; i <= k; i++){
		double now = p.top();
		p.pop();
		if(now <= x) break;
		p.push(x);
		p.push(now - x);
	}
	if(p.top() > x) return false;
	else return true;
}
inline int read(void){
	int num = 0, f = 1;
	char ch;
	while(!isdigit(ch=getchar())) if(ch == '-') f = -1;
	while(isdigit(ch)) num = num*10 + ch-'0', ch = getchar();
	return num * f;
}
int main()
{
	n = read(), k = read();
	for(int i = 1; i <= n; i++) a[i] = 1.0 * read();
	double l = 1, r = 1e9, ans;
	while(r - l > 0.001){
		double mid = (l+r) / 2;
		if(Check(mid)){
			ans = mid, r = mid;
		}
		else l = mid;
	}
	printf("%d\n", (int)ans+1);
	return 0;
}