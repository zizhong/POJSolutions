#include<stdio.h>
#include<string.h>
int com(int n, int r)
{
    int i, j, s = 1;
	if(n-r>r) r=n-r; 
     for(i=0,j=1;i<r;++i)
	{
       s *= (n-i);
       for( ; j <= r && s%j == 0; ++j ) s /= j;
	}
    return s;
}
int main()
{
   char str[15];
   int i,j,k,l,len,res;
   while(scanf("%s",str)!=EOF)
   {
       len=strlen(str);
       int flag=1;
       for( i=0;flag&&i<len; ++i )
           for(k=i+1;flag&&k<len;k++)
		     if(str[i]>=str[k]) 
                 {puts("0");flag=0;}
       if(!flag) continue;
       res = 0;
       for( j=1; j <= len; ++j ) res += com(26, j);
       for( l=0; str[l]; ++l ) res -= com(26-(str[l]-'a'+1), len-l);
       printf("%d\n",res);
   }
}
