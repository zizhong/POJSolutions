#include<stdio.h>
#include<string.h>
const int N=100;
int vc[N][N*4],nv1,nv2,vm1[N],vm2[N*4],vst[N*4];
int dfs(int n_v)
{
    for(int i=0;i<nv1;i++)
    {
        if(!vst[i]&&vc[n_v][i])
        {
            vst[i]=1;
            if(vm2[i]==-1||dfs(vm2[i]))
            {
                 vm1[n_v]=i;
                 vm2[i]=n_v;
                 return 1;
            }
        }
    }
    return 0;
}
char rec[N*4][N/2];
int nrec,rrec,rc[N*4][N*4],drec[N],nd;
char buf[1000];
int Find()
{
    int i;
    for(i=0;i<nrec;i++) if(!strcmp(buf,rec[i])) break;
    if(i==nrec) strcpy(rec[nrec++],buf);
    return i;
}
int main()
{
    int i,j,k,x,y,z,n;
    scanf("%d",&nrec);
    for(i=0;i<nrec;i++)
       scanf("%s",&rec[i]);
    rrec=nrec;
    scanf("%d",&nd);
    for(i=0;i<nd;i++)
    {
         scanf("%*s%s",buf);
         drec[i]=Find();
    }
    scanf("%d",&x);
    for(i=0;i<x;i++)
    {
        scanf("%s",buf);
        y=Find();
        scanf("%s",buf);
        z=Find();
        rc[y][z]=1;
    }    
    for(i=0;i<nrec;i++) rc[i][i]=1;
    for(k=0;k<nrec;k++)
       for(i=0;i<nrec;i++)
          for(j=0;j<nrec;j++)
              rc[i][j]=rc[i][j]||(rc[i][k]&&rc[k][j]);
    nv1=nd,nv2=rrec;
    for(i=0;i<nd;i++)
       for(j=0;j<rrec;j++)
           if(rc[drec[i]][j]) vc[i][j]=1;
    memset(vm1,-1,sizeof(vm1));
    memset(vm2,-1,sizeof(vm2));
    int ans=0;
    for(i=0;i<nd;i++)
       if(vm1[i]==-1)
       {
           memset(vst,0,sizeof(vst));
           if(dfs(i)==1) ans++;
       }
    printf("%d\n",nv1-ans);
    //scanf("%d",&ans);
}
