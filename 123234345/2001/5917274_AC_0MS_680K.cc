#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef struct {
	int num;
	char str[45];
	int len;
}Node;
int cmp1(const void *a,const void *b)
{
	return strcmp((*(Node *)a).str,(*(Node *)b).str);
}
int cmp2(const void *a,const void *b)
{
	return (*(Node *)a).num-(*(Node *)b).num;
}

int main()
{
	int i,j,n;
	Node data[1001];
	i=0;
	while(gets(data[i].str))
	{
		data[i].num=i+1;
		data[i].len=1;
		i++;
	}
	n=i;
	qsort(data,n,sizeof(data[0]),cmp1);
//	for(i=0;i<n;i++)
	//	cout<<data[i].str<<endl;
    	i=1;
      j=0;
		while(data[i].str[j]==data[i-1].str[j] && data[i].str[j]!='\0'&& data[i-1].str[j]!='\0')
		{
			data[i-1].len++;
			j++;
		}
	for(i=1;i<n-1;i++)
	{
		j=0;
		while(data[i].str[j]==data[i-1].str[j] && data[i].str[j]!='\0'&& data[i-1].str[j]!='\0')
		{
			data[i].len++;
			j++;
		}
			j=0;
	 while(data[i].str[j]==data[i+1].str[j] && data[i].str[j]!='\0'&& data[i+1].str[j]!='\0')
		{
			j++;
		}
	 if(j+1>data[i].len)
	 {
		 data[i].len=j+1;
	 }
	}
	j=0;
		while(data[i].str[j]==data[i-1].str[j] && data[i].str[j]!='\0'&& data[i-1].str[j]!='\0')
		{
			data[i].len++;
			j++;
		}
	qsort(data,n,sizeof(data[0]),cmp2);
	for(i=0;i<n;i++)
	{
//		cout<<data[i].len<<endl;
		cout<<data[i].str<<' ';
		for(j=0;j<data[i].len && data[i].str[j]!='\0';j++)
			cout<<data[i].str[j];
		cout<<endl;
	}
	return 0;
}
