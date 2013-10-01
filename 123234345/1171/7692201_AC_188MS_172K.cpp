#include <iostream>
#define MAX_L 8
#define MAX_A 26
#define MAX_R 1000
#define T(x) x-'a'
using namespace std;
int sum=0,mMax=-1,len,i,j;
int V[MAX_A];
char inStr[MAX_L];
int mCount[MAX_A]={0};
int mCountSave[MAX_A];
struct Record
{
	char inStr[MAX_L];
	int mCount[MAX_A];
	int mScore;
};
Record R[MAX_R];
int rtop=-1;
bool ok;
int main()
{
	V[T('q')]=7,V[T('w')]=6,V[T('e')]=1,V[T('r')]=2,V[T('t')]=2,V[T('y')]=5,V[T('u')]=4,V[T('i')]=1,V[T('o')]=3,V[T('p')]=5;
	V[T('a')]=2,V[T('s')]=1,V[T('d')]=4,V[T('f')]=6,V[T('g')]=5,V[T('h')]=5,V[T('j')]=7,V[T('k')]=6,V[T('l')]=3;
	V[T('z')]=7,V[T('x')]=7,V[T('c')]=4,V[T('v')]=6,V[T('b')]=5,V[T('n')]=2,V[T('m')]=5;
	scanf("%s",inStr);
	len=strlen(inStr);
	for(i=0;i<len;i++)
		mCount[T(inStr[i])]++;
	memcpy(mCountSave,mCount,sizeof(mCount));
	while(scanf("%s",inStr)&&inStr[0]!='.')
	{
		len=strlen(inStr);
		sum=0;
		ok=true;
		for(i=0;i<len;i++)
			if(inStr[i]!=' ')
			{
				if(mCount[T(inStr[i])])
				{
					mCount[T(inStr[i])]--;
					sum+=V[T(inStr[i])];
				}
				else 
				{
					ok=false;
					break;
				}
			}
			if(ok)
			{
				rtop++;
				memcpy(R[rtop].inStr,inStr,sizeof(inStr));
				memcpy(R[rtop].mCount,mCount,sizeof(mCount));
				R[rtop].mScore=sum;
				if(mMax<sum)
				{
					mMax=sum;
				}
			}
			memcpy(mCount,mCountSave,sizeof(mCount));
	}
    for(int i=0;i<=rtop;i++)
		for(int j=i+1;j<=rtop;j++)
		{
			ok=true;
			for(int k=0;k<26;k++)
				if(mCount[k]>R[i].mCount[k]+R[j].mCount[k])
				{
					ok=false;
					break;
				}
				if(ok)
				{
					sum=R[i].mScore+R[j].mScore;
					if(mMax<sum)
						mMax=sum;
				}
		}
		printf("%d\n",mMax);}
