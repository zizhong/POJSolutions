#include<stdio.h>
#include<string.h>
const int N=100001*2;
int wa[N],wb[N],wv[N],ws[N];
int cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int *r,int *sa,int n,int m)
{
     int i,j,p,*x=wa,*y=wb,*t;
     for(i=0;i<m;i++) ws[i]=0;
     for(i=0;i<n;i++) ws[x[i]=r[i]]++;
     for(i=1;i<m;i++) ws[i]+=ws[i-1];
     for(i=n-1;i>=0;i--) sa[--ws[x[i]]]=i;
     for(j=p=1;p<n;j*=2,m=p)
     {
          for(p=0,i=n-j;i<n;i++) y[p++]=i;
          for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
          for(i=0;i<n;i++) wv[i]=x[y[i]];
          for(i=0;i<m;i++) ws[i]=0;
          for(i=0;i<n;i++) ws[wv[i]]++;
          for(i=1;i<m;i++) ws[i]+=ws[i-1];
          for(i=n-1;i>=0;i--) sa[--ws[wv[i]]]=y[i];
          for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
              x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
     }
}
int rank[N],height[N];
void calheight(int *r,int *sa,int n)
{
     int i,j,k=0;
     for(i=1;i<=n;i++) rank[sa[i]]=i;
     for(i=0;i<n;height[rank[i++]]=k)
         for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++) ;
}
int r[N],sa[N];
char s[N];
int main()
{
    scanf("%s",s);
    int n1=strlen(s);
    s[n1]=1;
    scanf("%s",s+n1+1);
    int n2=strlen(s);
    for(int i=0;i<=n2;i++)
        r[i]=s[i];
    da(r,sa,n2+1,128);
    calheight(r,sa,n2);
    int ans=0;
    for(int i=1;i<=n2;i++)
       if(ans<height[i])
           if(sa[i]>n1&&sa[i-1]<n1||sa[i]<n1&&sa[i-1]>n1)
               ans=height[i];
    printf("%d\n",ans);
}
