#include<stdio.h>
int main()
{
   int ww,lw,lh;
   scanf("%d",&ww);
   int leftw=ww;
   int sw=0,sh=0,mh=0,mw=0;
   while(scanf("%d",&lw)&&lw)
   {   
       scanf("%d",&lh);
       if(lh==-1&&lw==-1)
       {
           sh+=mh;
           if(sw<mw) sw=mw;
           printf("%d x %d\n",sw,sh);
           sw=0,sh=0,mw=0,mh=0;
           scanf("%d",&ww);
           if(ww==0) return 0;
           continue;
       }
       if(lw<=leftw)
       {
           leftw-=lw;
           mw+=lw;
           if(lh>mh) mh=lh;
       }
       else
       {
           if(sw<mw) sw=mw;
           sh+=mh;
           leftw=ww;
           mh=lh,mw=0;
           leftw-=lw;
           mw+=lw;
           if(lh>mh) mh=lh;
       }
   }
     
}
