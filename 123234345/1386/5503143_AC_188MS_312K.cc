#include <stdio.h>
#include <string.h>
#define N 1005
#define clr(a) memset(a,0,sizeof(a))
#define abs(x) ((x)>0?(x):-(x))

int a[30],b[30];
char s[N];
char f[30];

char root(char p){
    int t,q=p;
    while(f[q]) q=f[q];
    while(f[p]){
        t=f[p];
        f[p]=q;
        p=t;
    }
    return q;
}

int main()
{
    int i,j,k,m,n,T;
    int count,flag,con;
    int p,q,r,v='a'-1;
    
    scanf("%d",&T);
    while(T--)
    {
        //init
        clr(a); clr(b);
        clr(f);
        
        //input
        scanf("%d",&n);
        getchar();
        for(i=0;i<n;i++){
            gets(s);
            
            m=strlen(s)-1;
            a[s[0]-v]++;
            b[s[m]-v]++;
            
            p=root(s[0]-v);
            q=root(s[m]-v);
            if(p!=q) f[p]=q;
        }
        
        //connected
        con=1;
        j=1;
        while(!(a[j]+b[j])) j++;
        r=root(j);
        for(i=j;i<=26&&con;i++)
            if((a[i]+b[i])&&root(i)!=r)
                con=0;
        
        //judge
        count=0;
        flag=con;
        
        for(i=1;i<=26&&flag;i++){
            if(a[i]!=b[i]) count++;
            if(count>2||abs(a[i]-b[i])>1) flag=0;
        }
        
        //output
        if(flag&&count<=2) puts("Ordering is possible.");
        else puts("The door cannot be opened.");
    }
    
    //system("pause");
    return 0;
}




