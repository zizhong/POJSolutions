#include<iostream>
#include<algorithm>
using namespace std;

struct Busroute{
      int start;
      int interval;
      int times;
      bool operator < (const Busroute & obj) const {
            return times > obj.times;
      }
};
Busroute Bus[910];
int arrive[60];
int total_bus,leftbus,mist ,c_nt;

bool check(int start,int interval)
{
    if(start + interval >= 60)  return false;
       for(int i = start; i < 60; i+= interval)
         if (! arrive[i]) return false;
     return true;
}
void update(int index,int flag)
{
      for (int i = Bus[index].start; i < 60; i+= Bus[index].interval)
         arrive[i] += flag,leftbus += flag;
}
void DFS(int index,int rts){
      if(leftbus == 0)
      {
          mist = mist < rts ? mist : rts;
          return;
      }
      else 
      {
            int tmp = index;
            while (tmp < c_nt && Bus[tmp].times > leftbus) tmp++;
            for(tmp; tmp < c_nt; tmp ++)
            {
                // 重要的剪枝
                if(rts + 1+(leftbus - Bus[tmp].times)/Bus[tmp].times >= mist)  return;
                if(check(Bus[tmp].start,Bus[tmp].interval))
                {
                    update(tmp,-1);
                    DFS(tmp,rts + 1);
                    update(tmp, 1);
                }
            }
      }
}
int slove(){
    mist = 17;
    leftbus = total_bus;
    DFS(0,0);
    return mist ;
}
int main(int argc, char* argv[])
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    //int tmp=clock();
    while(scanf("%d",&total_bus) != EOF)
    {
         int bus;
         memset(arrive,0,sizeof(arrive));
         for(int i = 0; i < total_bus; i++)
         {
             scanf("%d",&bus);
             arrive[bus]++;
         }
         c_nt = 0 ;
         for(int i = 0; i <= 29; i++) if(arrive[i])
             for(int j = i + 1; j < 59 - i; j++)
             {
                 if(check(i,j))
                 {
                     Bus[c_nt].start = i;
                     Bus[c_nt].interval = j;
                     Bus[c_nt++].times = 1 + (59 - i)/j;
                 }
            }
         sort(Bus,Bus + c_nt); 
         printf("%d\n",slove());
    }
    //int t=clock()-tmp;
    //printf("%d.%d s\n",t/1000,t%1000);
}
