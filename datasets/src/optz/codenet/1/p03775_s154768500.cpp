#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
int main(){
    long long N;
    cin>>N;
    double ans = 100;
    double logo;
    vector<long long> divisor;
    for(int i=1;i<=sqrt(N);i++){
        if(N%i==0){
            divisor.push_back(i);
            divisor.push_back(N/i);
        }
    }
    for(int i = 0;i<divisor.size();i=i+2){
        logo  = max(log10(divisor.at(i)),log10(divisor.at(i+1)));
        ans = min(floor(logo)+1,ans);
    }
    cout<<ans<<endl;
}