#include<stdio.h>
#include<string.h>
const int N=100;
int vc[N][N*4],nv1,nv2,vm1[N],vm2[N*4],vst[N*4];
int Bipartite()
{
    int i,j,k,x,y,z,n=0;
    int q[N*4],prev[N*4],qs,qe;
    for(i=0;i<nv1;i++) vm1[i]=-1;
    for(i=0;i<nv2;i++) vm2[i]=-1;
    for(i=0;i<nv1;i++)
    {
        qs=qe=0;
        for(j=0;j<nv2;j++)
        {
           prev[j]=-2;
           if(vc[i][j])
           {
               prev[j]=-1;
               q[qe++]=j;
           }
        }
        while(qs<qe)
        {
            x=q[qs];
            if(vm2[x]==-1) break;
            qs++;
            for(j=0;j<nv2;j++)
                if(prev[j]==-2&&vc[vm2[x]][j])
                {
                      prev[j]=x;
                      q[qe++]=j;
                }
        }
        if(qs==qe) continue;
        while(prev[x]>-1)
        {
            vm1[vm2[prev[x]]]=x;
            vm2[x]=vm2[prev[x]];
            x=prev[x];
        }
        vm2[x]=i;
        vm1[i]=x;
        n++;
    }
    return n;
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
    printf("%d\n",nv1-Bipartite());
    //scanf("%d",&x);
}
