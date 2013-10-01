#include <iostream>
#include<string.h>
using namespace std;
bool IsJava(char *str, int n) 
{
	int i;
	if (!( str[0] >='a' && str[0]<='z') ) 
		return false;
	for (i=1; i<=n-1; i++)
		if (str[i]=='_') 
			return false;
	return true;
}
bool IsCpp(char *str, int n)
{
	
	int i;
	if (!( str[0] >='a' && str[0]<='z') )
		return false;
	for (i=1; i<=n-1; i++)
	{
		if (str[i]>='a' && str[i]<='z')
			continue;
		else if (str[i]=='_' && str[i-1]=='_') 
			return false;
		else if(i==n-1 && str[i]=='_')
			return false;
		else if (str[i]>='A' && str[i]<='Z')
			return false;
	}
	return true;
}

void  JavaToCpp(char *str, int n)
{
	int i=0;
	for (i=0; i<=n-1; i++)
		if (str[i]>='A' && str[i]<='Z')
			cout<<"_"<<char(str[i]+32);
		else
			cout<<str[i];
	cout<<endl;
}
void  CppToJava(char *str, int n)
{
	int i=0;
	for (i=0; i<=n-1; i++)
		if (str[i] == '_')
			str[i+1] -= 32;
		else
			cout<<str[i];
	}
	cout<<endl;
}
int main()
{
    const int N=101;
	char str[N];
	bool isJava;
	bool isCpp;
	cin>>str;
	{
		isJava = IsJava(str, strlen(str));
		isCpp = IsCpp(str, strlen(str));
		if (isJava==false && isCpp==false)
			cout<<"Error!"<<endl;
		else if (isJava==true)
			JavaToCpp(str, strlen(str));
		else
			CppToJava(str, strlen(str));
	}
}