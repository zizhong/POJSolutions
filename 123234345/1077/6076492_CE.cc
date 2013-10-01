#include<iostream>
using namespace std;
typedef char Jigsaw[10];
const int fac[9] = {0, 1, 2, 6, 24, 120, 720, 5040, 40320};
char wayc[5]={"dlur"};
bool ch_state(Jigsaw & jigsaw,int ch)
{
     int i0,i;
     for(i0=0;i0<9;i0++)
        if(jigsaw[i0]=='9') break;
     bool flag=false;
     char temp;
     switch(ch)
     {
        case 0:
        if(i0>=3)
        {
           jigsaw[i0]=jigsaw[i0-3];
           jigsaw[i0-3]='9';
           flag=true;
        }
        break;
        case 1:
        if(i0%3<2)
        {
           jigsaw[i0] = jigsaw[i0+1];
           jigsaw[i0+1] = '9';
           flag = true;
        }
        break;
        case 2:
        if (i0 + 3 < 9)
        {
           jigsaw[i0] = jigsaw[i0+3];
           jigsaw[i0+3] = '9';
           flag = true;
        }
        break;
        case 3:
        if (i0 % 3 > 0)
        {
           jigsaw[i0] = jigsaw[i0-1];
           jigsaw[i0-1] = '9';
           flag = true;
        }
        break;
     }
     return flag;
}
int hashcode(Jigsaw jigsaw)
{
    int i,j;
    int code=0;
    for(i=0;i<9;i++)
    {
       int count=0;
       for(j=i+1;j<9;j++)
          if(jigsaw[i]>jigsaw[j]) count++;
       code+=count*fac[8-i];
    }
    return code;
}
typedef struct Jigsaw_Que
{
     Jigsaw jigsaw;
     int pre;
     char way;
};
Jigsaw_Que stateque[362880+10];
int hash[362880+10];
int main()
{
    memset(hash,-1,sizeof(hash));
    hash[0]=0;
    strcpy(stateque[0].jigsaw,"123456789");
    int pre=0;
    int front=0;
    int tail=1;
    stateque[0].way=0;
    while(tail!=front)
    {
        Jigsaw cur_state;
        strcpy(cur_state,stateque[front].jigsaw);
        front++;
        for(int k=0;k<4;k++)
        {
           Jigsaw new_state;
           strcpy(new_state,cur_state);
           if(ch_state(new_state,k))
           {
               int code=hashcode(new_state);
               if(hash[code]<0)
               {
                   hash[code]=tail;
                   strcpy(stateque[tail].jigsaw,new_state);
                   stateque[tail].pre=front-1;
                   stateque[tail].way=wayc[k];
                   tail++;
               }
           }
        }
    }
    int i=0;
    char js[10];
    while(1)
    {
           char c=getchar();
           if(c=='\n'||c==' ') continue;
           if(c=='x') c='9';
           js[i++]=c;
           if(i==9)
           {
                js[i]=0;
                break;
           }
    }
    Jigsaw temp;
    strcpy(temp,js);
    int idx=hashcode(temp);
    idx=hash[idx];
    if(idx<0) puts("unsolvable");
    else
    {
        char w[50];
        int top=0;
        while(1)
        {
                w[top++]=stateque[idx].way;
                idx=stateque[idx].pre;
                if(!idx)
                {
                        w[top]='\0';
                        puts(w);
                        break;
                }
        }
    }
    //scanf("%d",&idx);
}
