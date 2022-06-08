
 #include<iostream>
 #include<stdio.h>
 #include<cstdlib>
 #include<cstdio>
 #include<string>
 #include<math.h>
 #include<time.h>
 #include<iomanip>
 #include<algorithm>
 #include<string.h>
 #include<cctype>
 #include<fstream> 
 #include<map>
 #include<set>
 #include<vector>
 #include<sstream>
 #include<stack>
 #include<queue>
 #include<deque>
 #include<functional>
 #include<utility>
 #include<list>
 #include<memory>
 
 using namespace std;

 int main()
 {
   int n;
   int a[100005],b[100005],c[100005];
   
   while(cin>>n)
   {
     for(int i=0;i<n;i++) cin>>a[i];       
     for(int i=0;i<n;i++) cin>>b[i]; 
     for(int i=0;i<n;i++) cin>>c[i];
     sort(a,a+n);
     sort(b,b+n);
     sort(c,c+n);
     int j=0;
     int k=0;
     bool flag=false;
     long long int ans=0;
     for(int i=0;i<n;i++)
     {
       while(b[j]<=a[i]) j++;
       k=0;
       for(int s=j;s<n;s++)
       {
         while(c[k]<=b[s]) k++;
         ans=ans+(n-k);        
       } 
     }
     cout<<ans<<endl;                 
   }
   return 0;
 }