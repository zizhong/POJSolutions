#include<stdio.h>
main()
{
    while(1)
    {
     char s[11];   
     char a[11][11]={0},b[11][11]={0};
     int i,j,r,c;
     scanf("%s",s);
     if(strcmp(s,"ENDOFINPUT")==0) break;
     if(strcmp(s,"START")==0)
     {
        scanf("%d%d",&r,&c);
        for(i=0;i<r;i++)
           scanf("%s",a[i]);
        for(i=0;i<r-1;i++)
           for(j=0;j<c-1;j++)
           b[i][j]=(a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1])/4;        
        for(i=0;i<r-1;i++)
         {
          for(j=0;j<c-1;j++)
             printf("%c",b[i][j]);
           printf("\n");
         }
        scanf("%s",s);
     }
    }
}
