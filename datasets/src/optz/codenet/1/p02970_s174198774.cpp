#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  
   int n,d;
    cin >>n>>d;
    
    
    //i-D  i+D
    //cnt1 = D+1  eg if D=4  cnt1=5
    int x1=2*(d)+1; // here x1=9
    
    int rem=n-x1 ,cnt=1;
    
    int mul=n/x1;
    
    if(n==d || x1>=n)
    {
        cout << "1";
    }
    else if(rem<=x1 )
    {
        cout<<"2";
    }
    else if(n%x1==0 && rem!=x1)
    {
        
        while(mul)
        {
            cnt++;
            mul--;
        }
        cout << cnt;
    }
    else if(n%x1!=0)
    {
        while(mul)
        {
            cnt++;
            mul--;
        }
        cout << cnt;
    }
    
    
    
    return 0;
}

