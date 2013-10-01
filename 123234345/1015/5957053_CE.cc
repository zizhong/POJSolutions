// by duoshute

#include "iostream.h" 
#include "string.h" 

#define Mid 20*20+1 
#define Max 2*Mid+2 
unsigned int p2[21]; 
int ans[21][Max][11]; 
int sum[21][Max]; 
int minus[220]; 
int plus[220]; 

int i,j,k,l,n,m,p,t1,t2,s; 

void output(int i) 
{ 
    cout<<"Best jury has value "<<(sum[m][Mid+i]+i)/2<<" for prosecution and value "<<(sum[m][Mid+i]-i)/2<<" for defence:\n"; 
    for (p=0;p<=n/20;p++) 
        for (s=0;s<=20;s++) 
            if ((p2[s] & ans[m][Mid+i][p]) == p2[s]) 
                cout<<p*20+s+1<<' '; 
    cout<<endl<<endl; 
} 

void main() 
{ 
     
    for(p2[0]=1,i=1;i<=20;i++) p2[i]=2*p2[i-1]; 
    for(l=1;;l++) 
    { 
        cin>>n>>m; if (n==0) break;  
        cout<<"Jury #"<<l<<endl;  
        memset(ans,0,sizeof(ans)); 
        for (i=0;i<=20;i++) for (j=0;j<Max;j++) sum[i][j]=-1; 
        sum[0][Mid]=0;
        for (i=0;i<n;i++) {cin>>j>>k;minus[i]=j-k;plus[i]=j+k;} 

        for (i=0;i<n;i++) for (s=m;s>=1;s--) 
            for (j=Mid-20*m;j<=Mid+20*m;j++) if (sum[s-1][j]>=0)  
            { 
                t1=sum[s-1][j]+plus[i]; 
                t2=j+minus[i]; 
                if (t1>sum[s][t2])  
                { 
                    sum[s][t2]=t1; 
                    for (p=0;p<=i/20;p++) ans[s][t2][p]=ans[s-1][j][p]; 
                    ans[s][t2][i/20]+=p2[i%20]; 
                } 
            } 

        for (i=0;i<=20*m;i++) 
        { 
            if (sum[m][Mid-i]>=0 || sum[m][Mid+i]>=0)  
                if (sum[m][Mid-i]>sum[m][Mid+i]) {output(-i);break;} 
                else {output(i);break;} 
        } 
    } 
} 