#include<stdio.h>
#include<string.h>
char list[21][2][21];
int l,n;
int find(char *s)
{
    int i;
    for(i=0;i<l;i++)
       if(!strcmp(s,list[i][0])) return i;
    return -1;
}
int main()
{
    scanf("%d%d",&l,&n);
    for(int i=0;i<l;i++)
        scanf("%s%s",list[i][0],list[i][1]);
    for(int i=0;i<n;i++)
    {
        char str[21];
        scanf("%s",str);
        int f=find(str);
        if(f>=0) printf("%s\n",list[f][1]);
        else
        {
            int len=strlen(str);
            for(int j=0;j<len-1;j++) printf("%c",str[j]);
            if(str[len-1]=='y') printf("ies\n");
            else
            {
                printf("%c",str[len-1]);
                if(str[len-1]=='x'||str[len-1]=='o'||str[len-1]=='s'||(str[len-1]=='h'&&(str[len-2]=='c'||str[len-2]=='s')))
                    printf("es\n");
                else printf("s\n");
            }
        }
    }
}
