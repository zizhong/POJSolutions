#include<stdio.h>
#include<iostream>
#include<ctime>
#define maxn 100010
#define inf 1000000000
using namespace std;
typedef long long LL;
struct nodetype{
    int pos,x,rep;
}q[maxn];

struct node{
    LL key,pri;
    node *ch[2];
}*root,*Null,tree[maxn];

int n,tot=0,a[maxn],head=0,tail=-1;
LL f[maxn],s[maxn];
__int64 m;

node *New_Node(LL x){
    node *t=&tree[tot++];
    t->key=x,t->ch[0]=t->ch[1]=Null,t->pri=rand()*rand();
    return t;
}
void init(){
    srand(time(NULL));
    Null=New_Node(inf);
    Null->ch[0]=Null->ch[1]=Null,root=Null;
}
void Rotate(node* &x,int t){
    node *y=x->ch[t];
    x->ch[t]=y->ch[!t];
    y->ch[!t]=x,x=y;
}
void Insert(node* &now,node* x){
    if (now==Null) now=x;
    else{
        int t=x->key>now->key;
        Insert(now->ch[t],x);
        if (now->ch[t]->pri>now->pri) Rotate(now,t);
    }
}
node *get(node* x,node* y){
    if (x==Null) return y;
    else         return x;
}
void Remove(node* &now,LL x){
    if (now==Null) return;
    if (now->key!=x){
        int t=x>now->key;
        Remove(now->ch[t],x);
    }
    else{
        if (now->ch[0]==Null||now->ch[1]==Null) now=get(now->ch[0],now->ch[1]);
        else{
            int t=now->ch[1]->pri>now->ch[0]->pri;
            Rotate(now,t);
            Remove(now->ch[!t],x);
        }
    }
}
node *min(){
    node *now=root;
    while (now->ch[0]!=Null) now=now->ch[0];
    return now;
}
int main(){
    init();
      cin>>n>>m; s[0]=0,f[0]=0;
    bool can=true;
    for (int i=1;i<=n;i++){
        scanf("%d",a+i);
        s[i]=s[i-1]+a[i];
        if (a[i]>m) can=false;
    }
    if (!can) printf("%d\n",-1);
    else{
        q[++tail].pos=1,q[tail].x=a[1],f[1]=a[1];
        for (int i=1;i<=n;i++){
            int l=1,r=i,mid;
            while (l<r){
                mid=(l+r)>>1;
                if (s[i]-s[mid-1]<=m) r=mid;
                else                  l=mid+1;
            }
            int limit=l;
            while (head<=tail&&q[tail].x<=a[i]){
                if (tail!=head)
                    Remove(root,f[q[tail-1].pos]+q[tail].x);
                tail--;
            }
            while (head<=tail&&q[head].pos+1<limit){
                if (tail!=head)
                    Remove(root,f[q[head].pos]+q[head+1].x);
                head++;
            }
            q[++tail].pos=i,q[tail].x=a[i];
            if (tail!=head){
                q[tail].rep=f[q[tail-1].pos]+a[i];
                Insert(root,New_Node(q[tail].rep));
            }
            node *tmp=min();
            f[i]=f[limit-1]+q[head].x;
            if (tmp!=Null&&tmp->key<f[i]) f[i]=tmp->key;
            }
        cout<<f[n]<<endl;
        }
    return 0;
}
