#include <iostream>
#include <string>
#include <string.h>
using namespace std;
typedef long long LL;
int main(int argc, char* argv[])
{
	string S;
	cin>>S;
	LL ans=0;
	int i=0;
	int count=0;
	while (i<S.size()-1){
		if (S[i]=='B' && S[i+1]=='W'){
			S[i]='W';
			S[i+1]='B';
			ans++;
			if (i>0 && S[i-1]=='B'){
				i--;
			}else{
				i++;
				char *p=(char*)(S.c_str()+i);
				char *q=strchr(p,'W');
				if (!q){
					break;
				}


			}
		}else{
			i++;
		}
		count++;
	}
	cout<<ans<<endl;
	return 0;
}