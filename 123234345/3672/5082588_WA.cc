#include<iostream>
using namespace std;
main()
{
   double m; 
   int t,u,f,d;
   string s(100002,0);
   cin>>m>>t>>u>>f>>d;
   int i;
   for(i=0;i<t;i++)
      cin>>s[i];
   for(i=0;i<t&&m>0;i++)
   {
       int n=0;
       if(s[i]=='u') n=u;
       if(s[i]=='f') n=f;
       if(s[i]=='d') n=d;
       m-=2*n;
   }
   printf("%d\n",i);
}
