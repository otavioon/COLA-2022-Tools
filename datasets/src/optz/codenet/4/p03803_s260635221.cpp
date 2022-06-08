#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <istream>
#include <sstream>
#include <cctype>
#include <iomanip>
#define rep(i,N) for(int i=0;i<(int)N;++i)
//cout << fixed << setprecision(20) << *** << endl;
typedef long long ll;
using namespace std;
int main()
{
	ll N,M;
	string ANS="No";
	vector<vector<char>>A,B;
	cin>>N>>M;
	rep(i,N){
		vector<char>vec;
		string s;
		cin>>s;
		rep(j,N){
			vec.push_back(s[j]);
		}
		A.push_back(vec);
	}
	rep(i,M){
		vector<char>vec;
		string s;
		cin>>s;
		rep(j,M){
			vec.push_back(s[j]);
		}
		B.push_back(vec);
	}
	rep(i,N-M+1){
		rep(j,N-M+1){
			if(A[i][j]==B[0][0]){
				bool f=true;
				rep(k,N-M-1){
					rep(l,N-M-1){
						if(A[i+k][j+l]!=B[k][l])f=false;
					}
				}
				if(f==true)ANS="Yes";
			}
			//cout<<A[i][j];
		}
		//cout<<endl;
	}
	cout<<ANS<<endl;

}