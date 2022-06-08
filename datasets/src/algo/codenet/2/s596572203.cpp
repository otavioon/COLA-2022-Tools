#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int mintwo(int x)
{
    int ret=1;
    while(ret<=x)
        ret<<=1;
    return ret;
}
int main()
{
    int n;
    cin >> n;
    multiset<int> x;
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        x.insert(a);
    }
    int ret=0;
    while(!x.empty())
    {
        auto itr=--x.end();
        auto now=*itr;
        x.erase(itr);
        int h=mintwo(now);
        h-=now;
        auto p=x.find(h);
        if(p!=x.end())
        {
            x.erase(p);
            ret++;
        }
    }
    cout << ret << endl;
    return 0;
}
