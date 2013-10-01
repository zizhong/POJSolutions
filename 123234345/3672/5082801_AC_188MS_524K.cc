#include<iostream>
using namespace std;
main()
{ 
   int m,t,u,f,d;
   char s[100002]={0};
   cin>>m>>t>>u>>f>>d;
   int i;
   for(i=0;i<t;i++)
      cin>>s[i];
   s[i]=0;
   for(i=0;i<t&&m>0;i++)
   {
       int n=0;
       if(s[i]=='u') n=u+d;
       if(s[i]=='f') n=f+f;
       if(s[i]=='d') n=d+u;
       m-=n;
       if(m<0) i--;
   }
   printf("%d\n",i);
}
