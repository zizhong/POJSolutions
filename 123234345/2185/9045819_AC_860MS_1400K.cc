#include<cstdio>
#include<cstring>
char mat[10001][100];
int next[10005];
int r,c;
int min(int a,int b){return a>b?b:a;}
inline char getc(int p,bool dec,int k){
    if(dec)
         return mat[k][p];
    else return mat[p][k];             
}
int getpows(int p,bool dec){//1 c   0 r
     int n;
     if(dec)n=r;
     else n=c;
     next[0]=-1;int i,j;
     for(i=1,j=-1;i<n;i++)
     {
             while(j>-1&&getc(p,dec,j+1)!=getc(p,dec,i))j=next[j];
             if(getc(p,dec,j+1)==getc(p,dec,i))j++;
             next[i]=j;      
     }
     return n-1-next[n-1]; 
}
int gcd(int a,int b){
     return b?gcd(b,a%b):a;    
}
int lcm(int a,int b){
     return a/gcd(a,b)*b;    
}
int main(){
    
     scanf("%d%d",&r,&c);
     int i,j;
     for(i=0;i<r;i++)
         for(j=0;j<c;j++)
            scanf(" %c",&mat[i][j]);
     int res=1;
     int ans=1;
     for(i=0;i<r;i++)
          ans=min(c,lcm(ans,getpows(i,0))); 
     res*=ans;ans=1;                
     for(i=0;i<c;i++)
          ans=min(r,lcm(ans,getpows(i,1)));
     res*=ans;
     printf("%d\n",res);
}

