#include <iostream>
using namespace std;
int SafeStrcpy2KeyWord(char * pDestBuffer,char * pSourceString, int nDestBufferSize,char * szKeyWord)
{
	if(strcmp(szKeyWord,"END")==0)
	{
		return -2;
	}
	if(strcmp(szKeyWord,"NULL")==0)
	{
		return -1;
	}
	int lenkw=strlen(szKeyWord);

	for(int i=0;i<nDestBufferSize-lenkw+1;i++)
	{
		if(strncmp(pSourceString+i,szKeyWord,lenkw)==0)
		{
			strncpy(pDestBuffer,pSourceString,i);
			pDestBuffer[i]='\0';
			return i;
		}
	}
	strcpy(pDestBuffer,pSourceString);
	return nDestBufferSize;
}

int main()
{
	char pDestBuffer[260],pSourceString[260],szKeyWord[20];
	while(scanf("%s",pSourceString)!=EOF)
	{
		int lens=strlen(pSourceString);
		while(true)
		{
			scanf("%s",szKeyWord);
			int lend=SafeStrcpy2KeyWord(pDestBuffer,pSourceString,lens,szKeyWord);
			if(lend==-1)
				printf("0 NULL\n");
			else if(lend==-2)
				break;
			else if(lend==0)
				printf("0 NULL\n");
			else
				printf("%d %s\n",lend,pDestBuffer);
		}
	}
	return 0;
}
