#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<iostream>
#include<queue>
#include<set>
#include<string>
#include<utility>
#include<vector>

using namespace std;
 
typedef long long ll;

#define MP make_pair
#define F first
#define S second

int main(){
	int n,m;
    cin >> n >> m;
    vector<string> g(n);
    vector<string> t(m);
    for(int i=0;i<n;i++){
    	cin >> g.at(i);
    }
    for(int i=0;i<m;i++){
    	cin >> t.at(i);
    }
    for(int i=0;i<n-m+1;i++){
    	int tmp = (int)g.at(i).find(t.at(0));
        if(tmp==-1){
        	continue;
        }else if(tmp>n-m){
        	continue;
        }else{
        	for(int j=0;j<m;j++){
            	if(g.at(i+j).substr(tmp,m)!=t.at(j)){
                	break;
                }
                if(j==m-1){cout<<"Yes"<<  endl; return 0;}
            }
        }
    }
    cout << "No" << endl;
}
