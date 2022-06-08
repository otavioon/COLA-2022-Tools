#include <bits/stdc++.h>
using namespace std;
const long MOD = 1e9+7;
long floorSqrt(long x)  
{     
    if (x == 0 || x == 1)  
       return x; 
  
    // Do Binary Search for floor(sqrt(x)) 
    long start = 1, end = x, ans;    
    while (start <= end)  
    {         
        long mid = (start + end) / 2; 
  
        // If x is a perfect square 
        if (mid*mid == x) 
            return mid; 
  
        // Since we need floor, we update answer when mid*mid is  
        // smaller than x, and move closer to sqrt(x) 
        if (mid*mid < x)  
        { 
            start = mid + 1; 
            ans = mid; 
        }  
        else // If mid*mid is greater than x 
            end = mid-1;         
    } 
    return ans; 
} 
long digits(long n)
{
    long ans=0;
    while(n)
    {
        ans++;
        n/=10;
    }
    return ans;
}
int main()
{
    long test;
    test=1;
    // cin>>test;
    while(test--){
    long i,j,a,b,n,x,ans,most,index,c,maxi=0;
    cin>>n;
    a=floorSqrt(n);
    if(a*a==n)
    {
        cout<<digits(a);
    }
    else 
    {
        while(a>0)
        {
            if(n%a==0)
            {
                cout<<digits(n/a);
                break;
            }
            else a--;
        }
    }
    }
}