    #include <bits/stdc++.h>
    using namespace std;
    int main()
    {
        int a[3][3];
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                cin >>a[i][j];
        int d=a[1][0]-a[0][0];
        for(int i=0;i<3;i++)
        {
            if(a[1][i]-a[0][i]!=d || a[1][i]-a[2][i]!=d)
            {
                cout<<"NO";
                exit(0);
            }
        }
        cout<<"Yes";


        return 0;
    }