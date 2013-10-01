#include <string.h>
char a[100010][2][11], b[100010][11];
int main() 
{
   char s[100], (*p)[11];
   int k = 1, i = 0;
   while(gets(s)) 
   {
      if(s[0] == '\0') 
      {
      k = 0;
      qsort(a, i, 22 * sizeof(char), strcmp);
      continue;
      }
    if(k)
    {
     sscanf(s, "%s %s", a[i][1], a[i][0]);
     ++i;
    } 
    else 
    {
      p = bsearch(s, a, i, 22, strcmp);
      if(p) puts(p + 1);
      else puts("eh");
    }
   }
}
