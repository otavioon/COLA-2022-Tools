#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

//***********************************************
//*   ????????                                  * 
//*   ??????                                          *
//*   ???12?24?                                     * 
//***********************************************
int main()
{
   char a[35];
   cin.getline(a,32);                             //????? 
   int l=strlen(a);                               //???? 
   int i=0,k=0;
   while(i<l)
   {
      if(a[i]>='0' && a[i]<='9')                  //??????????? 
      {
         int count=1,j=i+1;
         while(a[j]>='0' && a[j]<='9')
         {
            count++;                              //????????? 
            j++;
         }
         for(k=i;k<i+count;k++)
         {
            cout<<a[k];                           //??????? 
         }
         cout<<endl;
         i=i+count;                               //?????i??????? 
      }
      else i++;
   }
   return 0;
}
