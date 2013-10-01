#include <iostream>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long int64;
typedef int T;
#define mem(a, b) memset(a, b, sizeof(a))
#define Sqr(x) ((x) * (x))
inline T Max(T a, T b) { if (a < b) a = b; return a; }
inline T Min(T a, T b) { if (a > b) a = b; return a; }
inline void Swap(T & a, T & b) { T t = a; a = b; b = t; }

const int maxn = 10005;
const int maxm = 100005;
const double EPS = 1e-10;
const int INF = INT_MAX / 2;

struct EDGE
{
    int a, b;
    int next;
};

int nx, ny, m;
EDGE edge[maxm];
int edge_num;
int first[maxn];
int cx[maxn], cy[maxn];// cx[i]表示xi对应的匹配，cy[i]表示yi对应的匹配.
int distx[maxn], disty[maxn]; // 层的概念，即在BFS中的第几层.

int que[maxn];
int head, tail;

int ans;



void Init(void)
{
    int i, j;
    fill(cx, cx + maxn, -1);
    fill(cy, cy + maxn, -1);
    fill(first, first + maxn, -1);
    edge_num = 0;
    ans = 0;
}

void AddEdge(int a, int b)
{
    edge[edge_num].a = a, edge[edge_num].b = b;
    edge[edge_num].next = first[a], first[a] = edge_num++;
}

bool BFS(void)
{
    int i, j, k;
    bool flag(0);
    int h, t;
    mem(distx, 0); mem(disty, 0);
    head = tail = 0;
    for (i = 1; i <= nx; i++)
    {
        if (cx[i] == -1) que[tail++] = i;
    }
    while (head != tail)
    {
        for (h = head, t = tail; h != t; h = (h + 1) % maxn)
        {
            i = que[h];
            for (k = first[i]; k != -1; k = edge[k].next)
            {
                j = edge[k].b;
                if (!disty[j])
                {
                    disty[j] = distx[i] + 1;
                    if (cy[j] == -1) flag = 1;
                    else
                    {
                        distx[cy[j]] = disty[j] + 1;
                        que[tail] = cy[j];
                        tail = (tail + 1) % maxn;
                    }
                }
            }
        }
        head = t;
    }
    return flag;
}

bool DFS(int i)
{
    int j, k;
    for (k = first[i]; k != -1; k = edge[k].next)
    {
        j = edge[k].b;
        if (disty[j] == distx[i] + 1)
        { // 说明j是i的后继结点.
            disty[j] = 0; // j被用过了，不能再作为其他点的后继结点了.
            if (cy[j] == -1 || DFS(cy[j]))
            {
                cx[i] = j, cy[j] = i;
                return 1;
            }
        }
    }
    return 0;
}

void sf(int x)
{
    int y,t;
    while(1)
      {
         if(getchar()=='(') 
            break;      
      }    
    scanf("%d",&t);
    while(1)
      {
         if(getchar()==')') 
            break;      
      }    
    
    while(t--)
     {
       scanf("%d",&y);
       AddEdge(x+1,y-nx+1);
         
     }
      
}

void Hopcroft_Karp(void)
{
    int i, j;
    while (BFS())
    {
        for (i = 1; i <= nx; i++)
        {
            if (cx[i] == -1 && DFS(i)) ans++;
        }
    }
  
}


int main()
{
   int i,j,k,m;
   while(scanf("%d",&nx)!=EOF)
     {  ny=nx;
        int x,y;
        Init();
        for(i=0;i<nx;i++)
          {
           scanf("%d",&x);
           sf(x);        
          }
        //for(i=0;i<n;i++,puts(""))
         // for(j=0;j<n;j++)
          //  printf("%d ",map[i][j]);
          Hopcroft_Karp();
        printf("%d\n",ans);
     }  
}