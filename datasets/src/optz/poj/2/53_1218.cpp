#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

/*
 * ?????.cpp
 *?????????????
 *  Created on: 2012-11-16
 *      Author: ???
 */



int main ()
{
	int n,k,i;              //n ????? ?k?????,i??????????????
	cin>>n>>k;              //?? n,k
	int apple[n];           //????apple??????????????
	apple[n-1]=k;
    do
    {
    	apple[n-1]=apple[n-1]+n;//????????????
    	for(i=n-2;i>=0;)
    	{
    		if(apple[i+1]%(n-1)==0)   //?????????????(n-1)??
    			{
    			apple[i]=apple[i+1]/(n-1)*n+k;//???????????
    		    i--;
    			}
    		else
    		  break;                  //?????
    	}
    }while(i>=0);                      //for ???????????
    cout<<apple[0]<<endl;             //??????
    return 0;
}