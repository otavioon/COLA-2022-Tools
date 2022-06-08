#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main(){
    const size_t size = 1e5;
    int N;
    cin >> N;
    int a[size] = {0};
    int b[size] = {0};
    int c[size] = {0};
    for (size_t i = 0; i < N; i++) cin >> a[i];
    for (size_t i = 0; i < N; i++) cin >> b[i];
    for (size_t i = 0; i < N; i++) cin >> c[i];

    sort(a, a+N);
    sort(b, b+N);
    sort(c, c+N);

    size_t num_a = 0;
    size_t num_c = 0;
    ll res = 0;
    for (size_t i = 0; i < N; i++){
	if ((b[i] <= a[0]) || (b[i] >= c[N-1])){
	    cout << "inIf" << endl;
	    continue;
	}
	while ((b[i] > a[num_a]) && (num_a < N)){
	    num_a++;
	}
	while ((b[i] >= c[num_c]) && (num_c < N)){
	    num_c++;
	}
	res += (num_a)*(N-num_c);
    }

    cout << res << endl;

    return 0;
}
