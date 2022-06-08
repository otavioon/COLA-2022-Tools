  
 #include<stdio.h>
int main()
{
  int a,b[5],sum=0,i,j,o;
  scanf("%d",&a);
  for(i=0;i<=a;i++)
    {
      scanf("%d",b[i]);
    }
  for (i=0;i<a-1;i++)
    {
      for(j=a-1;j>i;j--)
	{
	  if(b[j]<b[j+1])
	    {
	      o=b[j];
	      b[j]=b[j+1];
	      b[j+1]=o;
	      
	    }
	  else break;
	}
    }
  for(i=0;i<a;i++)
    {
      sum=sum+b[i];
    }
  printf("%d %d %d\n",b[0],b[a-1]);
  return 0;
}