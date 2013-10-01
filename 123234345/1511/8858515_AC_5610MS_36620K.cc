#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NN 1000004
#define INF 0x7fffffff

struct node{
       int sta;  //边的始点 
       int end;  //边的终点 
       int key;  //边的权值 
}edge[NN];

struct node1{
       int key;   //邻接的点 
       int next;  //下一个点的下标 
}pre[NN];

int n, p, q;
int que[NN], root[NN];
__int64 dis[NN];
char mark[NN];

void Add(int a, int b, int c, int id){
     int tmp;
     edge[id].sta = a;
     edge[id].end = b;
     edge[id].key = c;
     pre[id].key = b;
     pre[id].next = -1; 
     /*由于点很多，边相对较少，所以用邻接表来存*/
     if (root[a] == -1){
        root[a] = id;
     }else{
           tmp = root[a];
           while (pre[tmp].next != -1){
                 tmp = pre[tmp].next;
           }
           pre[tmp].next = id;
     }
}

void Spfa(){
     int i, num, tmp, cur;
     mark[1] = 1;
     que[0] = 1;
     num = 1;
     
     // dis赋初值 
     for (i = 1; i <= p; i++){
         dis[i] = INF;
     }
     
     tmp = root[1];
     dis[1] = 0;
     
     // 手动模拟队列 
     for (i = 0; i < num; i++){
         cur = que[i];
         tmp = root[cur];
         while (tmp != -1){
               if (dis[cur] + edge[tmp].key < dis[pre[tmp].key]){
                  if (!mark[pre[tmp].key]){
                  mark[pre[tmp].key] = 1;
                     que[num++] = pre[tmp].key;
                  }
                  dis[pre[tmp].key] = dis[cur] + edge[tmp].key;
               }
               tmp = pre[tmp].next;
         }
         mark[cur] = 0;
     }
}
int main()
{
    int i, a, b, c;
    __int64 sum;
    scanf("%d", &n);
    while (n--){
          scanf("%d%d", &p, &q);
          
          memset(root, -1, sizeof(root));
          for (i = 1; i <= q; i++){
                scanf("%d%d%d", &a, &b, &c);
                Add(a, b, c, i);
          }
          memset(mark, 0, sizeof(mark));
          Spfa();
          sum = 0;
          for (i = 2; i <= p; i++){
              sum += dis[i];
          }
          
          /*将所有的边反向一次，再求得的起点到其余各点的值即为原图中各点回到起点的值*/ 
          memset(root, -1, sizeof(root));
          for (i = 1; i <= q; i++){
              a = edge[i].end;
              b = edge[i].sta;
              c = edge[i].key;
              Add(a, b, c, i);
          }
          memset(mark, 0, sizeof(mark));
          Spfa();
          for (i = 2; i <= p; i++){
              sum += dis[i];
          }
          printf("%I64d\n", sum);  
    }
    return 0;
}

