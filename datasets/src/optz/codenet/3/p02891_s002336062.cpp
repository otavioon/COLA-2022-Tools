#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	string str;
	ll k;
while(	cin >> str >> k){
	

	int n = str.size();
	bool f = false;
	for(int i = 0; i < n - 1; i++){
		if(str[i] != str[i+1]){
			f = true;
			break;
		}
	}
	ll ans = 0;
	if(!f){		//如果全一样 
		ans = k * n / 2;
		printf("%lld\n",ans);
	}
	else{
		if(str[0] != str[n - 1]){		//如果首尾不一样 
			int m = 1, sum1 = 0; 
			for(int i = 0; i < n - 1; i++){	//直接找出有几个连续的	
				if(str[i] == str[i+1])
					m++;		
				else if(i != 0 && str[i] == str[i-1]){
					sum1 += m / 2;
					m = 1;		
				}
			}
//			cout << sum1 << endl;
			printf("%lld\n",sum1 * k);
		}
		else{
			//首先先找出从头开始几个连续，以及从尾开始几个连续
			int j = n - 1, i = 0;
			while(str[j] == str[j - 1])
				j--;
			while(str[i] == str[i + 1])
				i++;
			str += str;
			int sum1, sum2 = 0;	//i,j之间的连续数，还有剩下的数里面的连续数 
			sum1 = n - j + i + 1;
			int m = 1; 
			for(int g = i + 1; g < j; g++){	//直接找出有几个连续的	
				if(str[g] == str[g+1])
					m++;			
				else if(g != 0 && str[g] == str[g-1]){
					sum2 += m / 2;
					m = 1;		
				}
			}
//			printf("%d %d\n",i,j);			
//			printf("%d %d\n",sum1,sum2);
			//要加上两个连一起的，中间的，还有开头的和结尾的 如aabbaa
			ans =  sum1 / 2 * (k - 1) + sum2 * k + (i + 1) / 2 + (n - j) / 2;
			printf("%lld\n",ans);
		}
	}
	
	}
	return 0;
}