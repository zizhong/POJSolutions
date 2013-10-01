#include<stdio.h>
int back[6]={3,4,5,0,1,2};
int left[6][6];//left[i][j]表示面向i头顶j时的left方向，易知right[i][j]=back[left[i][j]]类似 
void pre()
{
     left[0][1]=2;left[0][2]=4;left[0][4]=5;left[0][5]=1;
     left[1][0]=5;left[1][2]=0;left[1][3]=2;left[1][5]=3;
     left[2][0]=1;left[2][1]=3;left[2][3]=4;left[2][4]=0;
     left[3][1]=back[2];left[3][2]=back[4];left[3][4]=back[5];left[3][5]=back[1];     
     left[4][0]=back[5];left[4][2]=back[0];left[4][3]=back[2];left[4][5]=back[3];
     left[5][0]=back[1];left[5][1]=back[3];left[5][3]=back[4];left[5][4]=back[0];
}
int main()
{
    pre();
    int m,n;
    scanf("%d",&m);
    while(m--)
    {
        int d[6]={0};
        int len,f=0,h=2;
        scanf("%d",&n);
        while(n--)
        {
            char cmd[10];
            int temp;
            scanf("%s%d",cmd,&len);
            switch (cmd[0])
            {
                   case 'l':
                        f=left[f][h];                        
                        break;
                   case 'r':
                        f=back[left[f][h]];
                        break;
                   case 'u':
                        temp=f;
                        f=h;
                        h=back[temp];
                        break;
                   case 'd':
                        temp=h;
                        h=f;
                        f=back[temp];
                        break;
                   case 'f':break;
                   case 'b':
                        f=back[f];
                        break;
            }
            d[f]+=len;
        }
        printf("%d %d %d %d\n",d[0]-d[back[0]],d[1]-d[back[1]],d[2]-d[back[2]],f);
    }
}
