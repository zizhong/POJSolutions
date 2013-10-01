/*
ID: zhangzz4
PROG: prime3
LANG: C++
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int N=99999+1,ten[]={1,10,100,1000,10000,100000,1000000};
int p[N],sum,x,xnum[800],x1num[10][500],pp[8000];
inline int dig(int num,int k){return num/ten[k]%10;}
int cntd(int x)
{
    int ans=0;
    while(x) ans+=x%10,x/=10;
    return ans;
}
void table()
{
    p[0]=p[1]=1;
    for(int i=2;i<N;i++)
       if(p[i]==0) 
       for(int j=i+i;j<N;j+=i)
            p[j]=1;
    for(int i=0;i<=99999;i++) if(p[i]==0)
    {
        if(i<=9999) {p[i]=1;continue;}
        int ans=cntd(i);
        if(ans==sum)
        {
            if(i/ten[4]==x) xnum[++xnum[0]]=i;
            pp[++pp[0]]=i;
            int d=dig(i,2);
            x1num[d][++x1num[d][0]]=i;
        }
        else p[i]=1;
    }
}
struct Jaw
{
    char w[5][5];
    char sw[26];
    void print()
    {
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
               putchar(w[i][j]+'0');
            puts("");
        }
    }
    char *str()
    {
        for(int i=0;i<5;i++)
           for(int j=0;j<5;j++)
               sw[i*5+j]=w[i][j];
        sw[25]=0;
        return sw;
    }
}jaw[1000];
int cnt;
char tmp[5][5];
int cmp(const void *a,const void *b)
{
    return strcmp(((Jaw *)a)->str() , ((Jaw *)b)->str());
}
int main()
{
  
    scanf("%d%d",&sum,&x);
    table();
    cnt=0;
    for(int i=1;i<=xnum[0];i++)
    {
        for(int h=0;h<5;h++) tmp[h][h]=dig(xnum[i],4-h);
        int d=tmp[2][2];
        for(int j=1;j<=x1num[d][0];j++) if(dig(x1num[d][j],4)%2)
        {
            for(int h=0;h<5;h++) tmp[4-h][h]=dig(x1num[d][j],4-h);
            for(int k=1;k<=x1num[d][0];k++) if(dig(x1num[d][k],4))
            {
                for(int h=0;h<5;h++) tmp[h][2]=dig(x1num[d][k],4-h);
                for(int g=1;g<=x1num[d][0];g++) if(dig(x1num[d][g],4))
                {
                    for(int h=0;h<5;h++) tmp[2][h]=dig(x1num[d][g],4-h);
                    int left1=sum-tmp[0][0]-tmp[0][2]-tmp[0][4];
                    if(left1>18) continue;
                    for(tmp[0][1]=1;tmp[0][1]<=9&&tmp[0][1]<left1;++tmp[0][1])
                    {
                        tmp[0][3]=left1-tmp[0][1];
                        tmp[4][1]=sum-tmp[0][1]-tmp[1][1]-tmp[2][1]-tmp[3][1];
                        if(tmp[4][1]%2==0) continue;
                        tmp[4][3]=sum-tmp[0][3]-tmp[1][3]-tmp[2][3]-tmp[3][3];
                        if(tmp[4][3]%2==0) continue;
                        if(tmp[4][1]<0||tmp[4][1]>9||tmp[4][3]<0||tmp[4][3]>9) continue;
                        if(p[ tmp[0][0]*ten[4]+tmp[0][1]*ten[3]+tmp[0][2]*ten[2]+tmp[0][3]*ten[1]+tmp[0][4] ] ||
                           p[ tmp[4][0]*ten[4]+tmp[4][1]*ten[3]+tmp[4][2]*ten[2]+tmp[4][3]*ten[1]+tmp[4][4] ] ||
                           p[ tmp[0][1]*ten[4]+tmp[1][1]*ten[3]+tmp[2][1]*ten[2]+tmp[3][1]*ten[1]+tmp[4][1] ] ||
                           p[ tmp[0][3]*ten[4]+tmp[1][3]*ten[3]+tmp[2][3]*ten[2]+tmp[3][3]*ten[1]+tmp[4][3] ])
                           continue;
                        int left2=sum-tmp[0][0]-tmp[2][0]-tmp[4][0];
                        if(left2>18) continue;
                        for(tmp[1][0]=1;tmp[1][0]<=9&&tmp[1][0]<left2;++tmp[1][0])
                        {
                                tmp[3][0]=left2-tmp[1][0];
                                tmp[1][4]=sum-tmp[1][0]-tmp[1][1]-tmp[1][2]-tmp[1][3];
                                if(tmp[1][4]%2==0) continue;
                                tmp[3][4]=sum-tmp[3][0]-tmp[3][1]-tmp[3][2]-tmp[3][3];                                
                                if(tmp[3][4]%2==0) continue;
                                if(tmp[1][4]<0||tmp[1][4]>9||tmp[3][4]<0||tmp[3][4]>9) continue;
                                if( p[ tmp[0][0]*ten[4]+tmp[1][0]*ten[3]+tmp[2][0]*ten[2]+tmp[3][0]*ten[1]+tmp[4][0] ] ||
                                    p[ tmp[0][4]*ten[4]+tmp[1][4]*ten[3]+tmp[2][4]*ten[2]+tmp[3][4]*ten[1]+tmp[4][4] ] ||
                                    p[ tmp[1][0]*ten[4]+tmp[1][1]*ten[3]+tmp[1][2]*ten[2]+tmp[1][3]*ten[1]+tmp[1][4] ] ||
                                    p[ tmp[3][0]*ten[4]+tmp[3][1]*ten[3]+tmp[3][2]*ten[2]+tmp[3][3]*ten[1]+tmp[3][4] ])
                                continue;
                                memcpy(jaw[cnt++].w,tmp,sizeof(tmp));
                        }                        
                    }
                }
            }
        }
    }
    if(cnt==0) puts("NONE");
    else
    {
        qsort(jaw,cnt,sizeof(jaw[0]),cmp);
        for(int i=0;i<cnt;i++)
        {
            if(i) puts("");
            jaw[i].print();
        }
    }
}
