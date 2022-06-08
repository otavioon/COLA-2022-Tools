#include <stdio.h>
#include <set>
using namespace std;

multiset<int> U;
int N,A[200200];

int main()
{
	scanf ("%d",&N);
	for (int i=0;i<N;i++) scanf ("%d",&A[i]), U.insert(A[i]);

	int ans = 0;
	for (int k=30;k>=1;k--){
		auto I = U.begin();
		while (I != U.end()){
			if (*I * 2 >= (1<<k)) break;
			auto J = U.find((1<<k)-*I);
			if (J != U.end()){
				auto K = I; ++K;
				U.erase(I);
				if (K == J) ++K;
				U.erase(J);
				ans++;
				I = K;
			}
			else ++I;
		}

		while (1){
			auto I = U.find(1<<(k-1));
			if (I != U.end()){
				auto J = I; ++J;
				if (J != U.end() && *I == *J){
					U.erase(I);
					U.erase(J);
					ans++;
				}
				else break;
			}
			else break;
		}
	}

	printf ("%d\n",ans);

	return 0;
}