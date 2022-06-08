#include<bits/stdc++.h>
using namespace std;
 
/*int Search(vector <long long int>v3,long long int n,long long int x){
      long long int low=0;
      long long int high=(n-1);
      while(low<=high){
         long long int mid=low+(high-low)/2;
          if(x==v3[mid]) return mid;
          if(x<v3[mid]) high=mid-1;
          if(x>v3[mid]) low=mid+1;
      }
    return -1;
}*/
int main()
{
    long long int ne,n,k,x,i,count=500,h,g,l,ish=500,r;
    vector<long long int> v;
    vector<long long int> v2;
    vector<long long int> v3;
    vector<long long int> fv;
    long long a[10];
    cin>>n>>k;
    for(i=0;i<10;i++){a[i]=0;}
    for(i=0;i<k;i++){
        cin>>x;
        a[x]++;
    }
  //cout<<a[0];
  for(i=0;i<10;i++){if(a[i]==0){v2.push_back(i);}}
  //cout<<v2[0];
   while(n>0){
       r=n%10;
      v3.push_back(r);
      n=n/10;
    }
    //cout<<v3[3]<<" "<<v3[2]<<" "<<v3[1]<<" "<<v3[0]<<"finish ";
    for(i=v3.size()-1;i>-1;i--){
        //cout<<a[v3[i]];
        if(a[v3[i]]==0)
        {fv.push_back(v3[i]);}
        else{
            if(v3[i]<9){
                while(a[v3[i]]!=0){v3[i]++;}
                if(v3[i]==10){g=i;count*=0;break;}
                ish*=0;fv.push_back(v3[i]);g=i;break;}
            else{g=i;
                count*=0;break;
            }
        }    
    }
    
    if(ish==0){for(h=g-1;h>=0;h--){fv.push_back(v2[0]);}}
    if(count==0&&ish!=0){for(h=g;h>=-1;h--){fv.push_back(v2[0]);}}
    for(l=0;l<fv.size();l++){cout<<fv[l];}
    return 0;
}
