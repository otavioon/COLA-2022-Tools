#include <iostream>
using namespace std;

int main() {
	int N; cin >> N;
	int a[100010];
	for(int i=0; i<N; ++i) cin >> a[i+1];
	int jo=0, light=1, l[100010], num=0;
	while(jo==0){
	    ++l[light];
	    light=a[light];
	    ++num;
	    if(l[light]) jo=2;
	    else if(light==2) jo=1;
	}
	if(jo==1) cout << num << endl;
	else cout << -1 << endl;
	return 0;
}
