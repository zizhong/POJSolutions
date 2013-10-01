#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
     int real[12]={0},lh[12]={0};
     char c1[15],c2[15],w[10];
     int t=3,i,r=0,s=0,max;
     while(t--)
     {
       scanf("%s%s%s",c1,c2,w);
       for(i=0;i<strlen(c1);i++)
       if(strcmp(w,"even")==0)         
             real[c1[i]-'A']=real[c2[i]-'A']=1;
       else if(strcmp(w,"up")==0)
            lh[c1[i]-'A']--,lh[c2[i]-'A']++;
       else if(strcmp(w,"down")==0)
            lh[c1[i]-'A']++,lh[c2[i]-'A']--;      
      }
      for(i=0;i<12;i++)
           if(real[i]) lh[i]=0;
       max=abs(lh[0]);
       r=0;
       if(lh[0]>=0) s=1;
       else s=-1;
       for(i=1;i<12;i++)
       {
          if(abs(lh[i])>max)
          {
          max=abs(lh[i]),r=i;
          if(lh[i]>=0) s=1;
          else s=-1;
          }
       }
       printf("%c is the counterfeit coin and it is ",r+'A');
       if(s>0) printf("light.\n");
       else printf("heavy.\n");
     }
}
