#include<bits/stdc++.h>

using namespace std;

bool has_only_allowed(int num,set<int>&allowed)
{
    while(num>0)
    {
        if(allowed.find(num%10)==allowed.end())
            return false;
        num/=10;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,i,j;
    cin>>n>>k;
    set<int>allowed;
    for(int i=0; i<10; i++)
    {
        allowed.insert(i);
    }
    for(set<int>::iterator it=allowed.begin(); it!=allowed.end(); ++it){
        cout << ' ' << *it;

}
  cout << '\n';
//cout<< allowed<< "\n";
for(int i=0; i<k; i++)
{
    int a;
    cin>>a;
    allowed.erase(a);
}
 for(set<int>::iterator it=allowed.begin(); it!=allowed.end(); ++it){
        cout << ' ' << *it;

}
    cout << '\n';

while(true)
{
    if(has_only_allowed(n,allowed))
    {
        cout<<n;
        break;
    }
    n++;
}
cout<< "\n";
return 0;
}

