#include<stdio.h>
#include<string.h>
#define MAX 1100
char str[MAX][25];
const int sonnum=26,base='a';
struct Trie
{
	int num;
	bool  terminal;
	struct Trie *son[sonnum];
};
Trie *NewTrie()
{
	Trie *temp=new Trie;
	temp->num=1;temp->terminal=false;
	for(int i=0;i<sonnum;i++) temp->son[i]=NULL;
	return temp;
}
void Insert(Trie *pnt,char *s,int len)
{
	Trie *temp=pnt;
	for(int i=0;i<len;i++)
	{
		if(temp->son[s[i]-base]==NULL) temp->son[s[i]-base]=NewTrie();
		else temp->son[s[i]-base]->num++;
		temp=temp->son[s[i]-base];
    }
	temp->terminal=true;
}
void Delete(Trie *pnt)
{
	if(pnt!=NULL)
	{
		for(int i=0;i<sonnum;i++) if(pnt->son[i]!=NULL)  Delete(pnt->son[i]);
		delete pnt;
		pnt=NULL;
	}
}
Trie*Find(Trie *pnt,char *s,int len)
{
	Trie *temp=pnt;
	for(int i=0;i<len;i++)
	{
		if(temp->son[s[i]-base]!=NULL) {printf("%c",s[i]);temp=temp->son[s[i]-base];if(temp->num==1) break;} 
		else return NULL;
	}
	return temp;
}
void solve(Trie *pnt,int num)
{
	for(int i=0;i<num;i++)
	{
		printf("%s ",str[i]);
		int len=strlen(str[i]);
		Find(pnt,str[i],len);
		printf("\n");
	}
}
int main()
{
	int num=0,len;
	Trie *pnt=NewTrie();
	while(scanf("%s",str[num])!=EOF)
	{
		len=strlen(str[num]);
		Insert(pnt,str[num],len);
		num++;
	}
	solve(pnt,num);
	Delete(pnt);
	return 0;
}