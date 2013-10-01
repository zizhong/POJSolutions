#include<string.h>
#include<stdlib.h>
#include<stdio.h>
char dict[100000][2][11];

int main() 
{
   char s[50], (*p)[11];
   int k = 1, i = 0;
   while(gets(s)) 
   {
		 if(s[0] == '\0') 
		 {
			  k = 0;
			  qsort(dict, i, 22 * sizeof(char), strcmp);
			  continue;
		 }
		if(k)
		{
			 sscanf(s, "%s %s", dict[i][1], dict[i][0]);
			 ++i;
		} 
		else 
		{
			  p = bsearch(s, dict, i, 22, strcmp);
			  if(p) puts(p + 1);
			  else puts("eh");
		}
   }
}
