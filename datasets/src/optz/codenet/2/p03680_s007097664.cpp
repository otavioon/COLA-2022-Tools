#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <cmath>

#define YESNO(x) x ? printf("YES") : printf("NO")
#define YesNo(x) x ? printf("Yes") : printf("No")
#define scani(x) scanf("%d", &x)
#define printi(x) printf("%d", x)

using namespace std;

//ABC065B - Trained?
int Main() {
	int n;
	struct btn {
		int num;
		bool touch;
	};
	vector<btn> a;
	int ans = 0;
	int next = 0;

	scani(n);
	a.resize(n);	for (auto& btn : a) {
		scani(btn.num);
		btn.touch = false;
	}

	//check
	while (1 != next && false == a[next].touch) {
		a[next].touch = true;
		next = a[next].num - 1;
		ans++;
	}
	if (1 != next) ans = -1;

	printi(ans);

	return 0;
}


int main()
{
	Main();
	return 0;
}