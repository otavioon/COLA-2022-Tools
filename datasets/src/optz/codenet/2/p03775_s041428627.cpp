#include <bits/stdc++.h>
using namespace std;

long long caldigit(long long  num) {
    long long digit=0;
    while(num!=0) {
        num/=10;
        digit++;
    }
    return digit;
}

int main() {
    long long n;
    cin>>n;
    vector<long long> ans;
    fill(ans.begin(),ans.end(),0);
    for(long long i=1;i*i<n;i++) {
        if(n%i==0) {
            long long a,b;
            a=caldigit(i);
            b=caldigit(n/i);
            ans.push_back(max(a,b));
        }
    }
    cout<<*min_element(ans.begin(),ans.end())<<endl;
    return 0;
}
