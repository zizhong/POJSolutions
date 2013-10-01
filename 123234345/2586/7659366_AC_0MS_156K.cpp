#include<stdio.h>
int main(){
    int s,d,ans;
    while(scanf("%d%d",&s,&d)!=EOF){
        if(s-4*d>0)ans=-1;
        else if(4*s-d<=0)ans=10*s-2*d;
        else if(3*s-2*d<=0)ans=8*s-4*d;
        else if(2*s-3*d<=0)ans=6*s-6*d;
        else if(s-4*d<=0)ans=3*s-9*d;
        else ans=-1;
        if(ans<0)puts("Deficit");
        else printf("%d\n",ans);
    }
}
