#include<stdio.h>
char dic[100][100];
char ndic[100][100];
char mar[100][100];
int cmp1(const void *a,const void *b)
{
    return *(char *)a-*(char *)b;
}
int cmp2(const void *a,const void *b)
{
    return strcmp((char *)a,(char *)b);
}
int main()
{
    char str[100];
    int i=0;
    while(scanf("%s",str)&&strcmp(str,"XXXXXX"))
    {
        strcpy(dic[i],str);
        qsort(str,strlen(str),sizeof(char),cmp1);
        strcpy(ndic[i],str);
        i++;
    }
    while(scanf("%s",str)&&strcmp(str,"XXXXXX"))
    {
        int num=0,j;
        qsort(str,strlen(str),sizeof(char),cmp1);
        for(j=0;j<i;j++)
           if(strcmp(str,ndic[j])==0)
              strcpy(mar[num++],dic[j]);
        if(num==0) printf("NOT A VALID WORD\n");
        else
        {
        qsort(mar,num,sizeof(mar[0]),cmp2);
        for(j=0;j<num;j++)
           printf("%s\n",mar[j]);
        }
        printf("******\n");
    }
}
