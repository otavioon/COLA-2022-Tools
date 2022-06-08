# include<iostream>
# include<cstring>
using namespace std;
int main ()
{
	 string s;
	 cin>>s;
	 int k;
	 cin>>k;
	 long long  sum =0;
	 for(int i=0;i<s.length();)
	 {
	 	 int j=i+1;
	 	 int l=0;
	 	 while(j<s.length()&&s[j]==s[i])
	 	 {
	 	 	 j++;
	 	 	 l++;
		  }
		  //cout<<"l="<<l<<endl;
		  i=j;
		  sum += (l+1)/2;
	 }
	 char s1[200];
	 for(int i=0;i<2*s.length();i++)
	 {
	 	 
	 	  s1[i] =s[i%s.length()];
	 	  
	 }
	 
	 long long  sum1 =0;
	 for(int i=0;i<strlen(s1);)
	 {
	 	 int j=i+1;
	 	 int l=0;
	 	 while(j<strlen(s1)&&s1[j]==s1[i])
	 	 {
	 	 	 j++;
	 	 	 l++;
		  }
		  //cout<<"l="<<l<<endl;
		  i=j;
		  sum1 += (l+1)/2;
	 }	
	 
	 
	 long long sum2 = sum + (sum1-sum)*(k-1);
	 cout<<sum2<<endl;
	 
 } 