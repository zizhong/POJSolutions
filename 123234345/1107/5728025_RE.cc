#include<stdio.h>
#include<string.h>
int main()
{
    int k1,k2,k3;
    while(scanf("%d%d%d",&k1,&k2,&k3),k1||k2||k3)
    {
         char s[128],s2[128];
         int c1[128],c2[128],c3[128],d1[128],d2[128],d3[128];
         gets(s),gets(s);
         int n1=0,n2=0,n3=0,n=strlen(s);
         for(int i=0;i<n;i++)
            if(s[i]>='a'&&s[i]<='i') c1[n1++]=i;
            else if(s[i]>='j'&&s[i]<='r') c2[n2++]=i;
            else c3[n3++]=i;
         k1%=n1,k2%=n2,k3%=n3;
         for(int i=0;i<n1;i++) d1[i]=c1[(i+k1)%n1];
         for(int i=0;i<n2;i++) d2[i]=c2[(i+k2)%n2];
         for(int i=0;i<n3;i++) d3[i]=c3[(i+k3)%n3];
         n1=n2=n3=0;
         for(int i=0;i<n;i++)
         {
                 if(s[i]>='a'&&s[i]<='i') s2[d1[n1++]]=s[i];
                 else if(s[i]>='j'&&s[i]<='r') s2[d2[n2++]]=s[i];
                 else s2[d3[n3++]]=s[i];
         }
         s2[n]=0;
         puts(s2);
    }
}
