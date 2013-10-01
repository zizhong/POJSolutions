/*
ID: zhangzz4
PROG: prime3
LANG: C++
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int N=99999+1,ten[]={1,10,100,1000,10000,100000,1000000};
int p[N],sum,x,odd[1000],noZx[10][1000],xnum[10][1000];
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
            int flag_odd=1,flag_zero=1;
            for(int j=0;j<5;j++)
            {
              if(dig(i,j)%2==0) flag_odd=0;
              if(dig(i,j)==0) flag_zero=0;
            }
            if(flag_odd) odd[++odd[0]]=i;
            if(dig(i,4)==x)
            {
                xnum[i%10][++xnum[i%10][0]]=i;
                if(flag_zero) noZx[i%10][++noZx[i%10][0]]=i;
            }
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
    for(int i=1;i<=odd[0];i++)
    {
        for(int h=0;h<5;h++) tmp[h][4]=dig(odd[i],4-h);
        for(int j=1;j<=odd[0];j++) if(odd[j]%10 == tmp[4][4])
        {
            for(int h=0;h<5;h++) tmp[4][h]=dig(odd[j],4-h);
            for(int k=1;k<=noZx[tmp[0][4]][0];k++)
            {
                for(int h=0;h<5;h++) tmp[0][h]=dig(noZx[tmp[0][4]][k],4-h);
                for(int m=1;m<=noZx[tmp[4][0]][0];m++)
                {
                    for(int h=0;h<5;h++) tmp[h][0]=dig(noZx[tmp[4][0]][m],4-h);
                    for(int n=1;n<=xnum[tmp[4][4]][0];n++)
                    {
                        for(int h=1;h<4;h++) tmp[h][h]=dig(xnum[tmp[4][4]][n],4-h);
                        for(int d=0;d<10;d++)
                        {
                            tmp[1][2]=d;
                            tmp[1][3]=sum-tmp[1][0]-tmp[1][1]-tmp[1][2]-tmp[1][4];
                            if(tmp[1][3]<0||tmp[1][3]>9) continue;
                            tmp[2][3]=sum-tmp[0][3]-tmp[1][3]-tmp[3][3]-tmp[4][3];
                            if(tmp[2][3]<0||tmp[2][3]>9) continue;
                            tmp[3][2]=sum-tmp[0][2]-tmp[1][2]-tmp[2][2]-tmp[4][2];
                            if(tmp[3][2]<0||tmp[3][2]>9) continue;
                            tmp[3][1]=sum-tmp[3][0]-tmp[3][2]-tmp[3][3]-tmp[3][4];
                            if(tmp[3][1]<0||tmp[3][1]>9) continue;
                            tmp[2][1]=sum-tmp[2][0]-tmp[2][2]-tmp[2][3]-tmp[2][4];
                            if(tmp[2][1]<0||tmp[2][1]>9) continue;
                            if(p[ (((tmp[0][1]*10+tmp[1][1])*10+tmp[2][1])*10+tmp[3][1])*10+tmp[4][1] ] ||
                               p[ (((tmp[0][2]*10+tmp[1][2])*10+tmp[2][2])*10+tmp[3][2])*10+tmp[4][2] ] || 
                               p[ (((tmp[0][3]*10+tmp[1][3])*10+tmp[2][3])*10+tmp[3][3])*10+tmp[4][3] ] ||
                               p[ (((tmp[1][0]*10+tmp[1][1])*10+tmp[1][2])*10+tmp[1][3])*10+tmp[1][4] ] ||
                               p[ (((tmp[2][0]*10+tmp[2][1])*10+tmp[2][2])*10+tmp[2][3])*10+tmp[2][4] ] ||
                               p[ (((tmp[3][0]*10+tmp[3][1])*10+tmp[3][2])*10+tmp[3][3])*10+tmp[3][4] ] ||
                               p[ (((tmp[4][0]*10+tmp[3][1])*10+tmp[2][2])*10+tmp[1][3])*10+tmp[1][4] ] )
                               continue;
                            for(int t=0;t<5;t++) for(int y=0;y<5;y++) jaw[cnt].w[t][y]=tmp[t][y];
                            cnt++;
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
