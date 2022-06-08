#include<bits/stdc++.h>
using namespace std;

int main()
{
    string n;
    int k, curr=0, num, f=0;
    cin>>n>>k;
    vector<int> a(k);
    for(int i=0;i<k;++i)
    cin>>a[i];
    for(int i=n.length()-1;i>=0;--i)
    {
        num = n[i]-'0';
        curr=num;
        if((curr==9 || find(a.begin(), a.end(), curr)==a.end()) && f==0)
        continue;
        int j = upper_bound(a.begin(), a.end(), curr)-a.begin();
        j--;
        if(f!=0)
        {
            curr=0;
            j=0;
        }
        while(curr==a[j])
        {
            curr++;
            j++;
        }
        n[i] = curr+'0';
        f=1;
    }
    cout<<n<<endl;
    return 0;
}