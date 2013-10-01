#include<stdio.h>
main()
{
    char s[11]={0};
    int i,mi,v;
    scanf("%s",s);
    for(i=0;i<10;i++)
      if(s[i]=='?')
         mi=i;
    v=0;
    for(i=0;i<10;i++)
      if(i!=mi)
      {
        if(s[i]=='X')
          v+=10*(10-i);
        else v+=(s[i]-'0')*(10-i);
      }
    for(i=0;i<=10;i++)
       if((v+(10-mi)*i)%11==0)
       {
         if(i==10)
         {
         if(mi==9)
           printf("X\n");
         else i=11;
         }
         else printf("%d\n",i);
         break;
       }
    if(i==11) printf("-1\n");
}
