#include<stdio.h>
int sub(char* s1,char *s2)
{
    int i,j;
    if(strlen(s1)<strlen(s2)) return 0;
    for(i=0,j=0;i<strlen(s1)&&j<strlen(s2);i++)
         if(s1[i]==s2[j]) j++;
    if(j<strlen(s2)) return 0;
    return 1;
}
main()
{
   int n,i;
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       char str1[101]={0},str2[101]={0};
       scanf("%s%s",str1,str2);
       if(sub(str1,str2)) 
           printf("YES\n");
       else{
              strrev(str2);
              if(sub(str1,str2))  printf("YES\n");
              else printf("NO\n");
           }
   }
}
