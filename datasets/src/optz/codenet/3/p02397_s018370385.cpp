#include<bits/stdc++.h>

using namespace std;

int main()
{
    for(int i=0;i<10000;i++)
    {
        vector<int> a(2,0);
        cin >> a.at(0) >> a.at(1);
        if(a.at(0)==0&&a.at(1)==0)
        {
            return(0);
        }
        sort(a.begin(),a.end());
            cout << a.at(0) << " " << a.at(1) << endl;
    }
    return(0);
}
