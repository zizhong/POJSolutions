#include<iostream>

using namespace std;

int board[10][10];

int n,k,c;

void dfs(int num)

{

    if(num>k)

    {

        c++;

        return;

    }

    for(int u=num-1;u<n;u++)

    { 

        if(k-num>n-1-u) 

            return;

        for(int i=0;i<n;i++)

        {

   //同一行不允许存在两个棋子

            if(board>0) 

                break;

            if(board==0)

            {

                int j;

    //同一行不允许存在两个棋子

                for(j=i+1;j<n;j++) 

                    if(board[j]>0) 

                        break;

                if(j<n) 

                    break;

    //同一列不允许存在两个棋子

                for(j=0;j<u;j++) 

                    if(board[j]>0) 

                        break;

                if(j==u)

                {

                    board=num;

                    dfs(num+1);

                    board=0;

                }

            }

        }

    }

}

int main()

{

 //ifstream cin("input.txt");

    char str[10];

    while(1)

    {

        cin>>n>>k;

        if(n==-1 && k==-1) break;

        for(int i=0;i<n;i++)

        {

            cin>>str;

            for(int j=0;j<n;j++)

            {

                if(str[j]=='#') 

                    board[j]=0;

                else 

                    board[j]=-1;

            }

        }

        c=0;

        dfs(1);

        cout<<c<<endl;

    }

}

