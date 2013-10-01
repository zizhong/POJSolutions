#include<stdio.h>
int a[10000000];
char stands[8];
char maps(char c)
{
   if(c=='A'||c=='B'||c=='C') return '2';
   if(c=='F'||c=='D'||c=='E') return '3';
   if(c=='I'||c=='G'||c=='H') return '4';
   if(c=='L'||c=='J'||c=='K') return '5';
   if(c=='O'||c=='M'||c=='N') return '6';
   if(c=='P'||c=='R'||c=='S') return '7';
   if(c=='T'||c=='U'||c=='V') return '8';
   if(c=='W'||c=='X'||c=='Y') return '9';
}
void change(char* s)
{
   int i,j=0;
   for(i=0;i<strlen(s);i++)
   {
      if(s[i]>='0'&&s[i]<='9')
         stands[j++]=s[i];
      else if(s[i]>='A'&&s[i]<'Z'&&s[i]!='Q')
         stands[j++]=maps(s[i]);
   }
}
int main()
{
   int n,i,flag=0;
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
      int num=0;
      char str[128]={0};
      scanf("%s",str);
      change(str);
      sscanf(stands,"%d",&num);
      a[num]++;
   }
   for(i=0;i<=9999999;i++)
     if(a[i]>1)
     {
       flag=1;
       printf("%d%d%d-%d%d%d%d %d\n",i/1000000,i/100000%10,i/10000%10,i/1000%10,i/100%10,i/10%10,i%10,a[i]);
     }
   if(!flag)
      printf("No duplicates.\n");
}
