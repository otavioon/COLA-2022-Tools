#include<iostream>
#include<string>
#include<algorithm>
#include <sstream>
#include<cmath>
#include<map>
#include<iomanip>
#include<queue>
#include <vector>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
int main()
{

 	ll n;
 	scanf("%lld",&n);
 	int t=1;
 	ll m = n;
 	ll k =sqrt(n);
 	    for(int i=2;i<n/i;i++)

        if(n%i==0){

            n=n/i;
            t=t*i;
            i--;
        //    cout<<"n = "<<n<<" t = "<<t<<endl;
            if(t>=n)break;

        }
      //  cout<<endl;
    /*-int i=2;
    while(t>n){
        if(t%i==0)
        {
            n=n*i;
            t=t/i;
            i--;
             cout<<"n = "<<n<<" t = "<<t<<endl;
        }
        i++;
    }*/


    stringstream s1;
    s1<<n;
    cout<<"n = "<<n<<" t = "<<t<<endl;
    string str1,str2;
    s1>>str1;
    s1<<t;
    s1>>str2;
    cout<<max(str1.size(),str2.size())<<endl;
	return 0;
}
