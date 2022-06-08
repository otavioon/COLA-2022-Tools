#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int INF = 1<<30;

int main(){
  int d1, d2;bool ans=true;
  for(int i=0;i<3;i++){
  	int a, b, c;cin>>a>>b>>c;
    if(i==0){
    	d1=b-a;d2=c-a;
    }else{
    	if(!(d1==b-a&&d2==c-a)){ans=false;break;}
    }
  }
  cout<<(ans?"Yes":"No")<<endl;
}
