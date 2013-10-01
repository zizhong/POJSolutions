#include<iostream>
#include<stack>
#include<string>
#include<map>
using namespace std;
map<char,int> m;
char ch[81];
int isLetter(char ch)
{
	if(ch>='a'&&ch<='z'||ch>='0'&&ch<='9')
		return 1;
	return 0;
}
int convert(char c[81])
{
	int len = strlen(c);

	stack<char> s;
	int j=0;
	for(int i=0;i<len;i++)
	{
		if(isLetter(c[i]))
		{
			ch[j++]=c[i];
		}
		else
		{
			switch(c[i])
			{
				case '(':s.push(c[i]);break;
				case '+':
				case '-':
				case '*':
					while(!s.empty()&&m[s.top()]>=m[c[i]])
					{
						ch[j++]=s.top();
						s.pop();
					}
					s.push(c[i]);
					break;
				case ')':
					while(s.top()!='(')
					{
						ch[j++] = s.top();
						s.pop();
					}
					s.pop();
			}
		}
	}
	while(!s.empty())
	{
		ch[j++] = s.top();
		s.pop();
	}
	return j;
}
int result(int len)
{	int final = 0;
	stack<int> s;
	for(int i=0;i<len;i++)
	{
		if(ch[i]>='a'&&ch[i]<='z')
		{			
			s.push((int)ch[i]);
		}
		else if(ch[i]>='0'&&ch[i]<='9')
		{
			s.push(ch[i]-'0');
		}
		else
		{		
			int temp1 = s.top();
			s.pop();
			int temp2 = s.top();
			s.pop();
			switch(ch[i]){
			
				case '+':final = temp1 + temp2;s.push(final);break;
				case '-':final = temp2 - temp1;s.push(final);break;
				case '*':final = temp1 * temp2;s.push(final);break;
			}
		}
	}
	return s.top();
}
int main()
{
	int nums;
	cin>>nums;
	char ch[81];
	char ch1[81];
	m['+']=1;
	m['-']=1;
	m['*']=2;
	m['(']=0;
	getchar();
	for(int i=0;i<nums;i++)
	{
		gets(ch);
		gets(ch1);
		int x = result(convert(ch));
		int y = result(convert(ch1));
		if(x == y)
			cout<<"YES"<<endl;
		else cout<<"NO"<<endl;

	}}
