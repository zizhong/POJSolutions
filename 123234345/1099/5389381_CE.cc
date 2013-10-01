#include <iostream>
using namespace std;
int main()
{
	int i,j,m,p,q,c;
	char format[41][45];
	int ASM[11][11];
	bool qislian;
	c=1;
	while (cin>>m)
	{
		if(m==0) break;
		if(c!=1) cout<<endl;
		cout<<"Case "<<c<<":"<<endl<<endl;
		c++;
		for (i=0;i<m;i++)
		{
			for (j=0;j<m;j++)
			{
				cin>>ASM[i][j];
			}
		}
		for (i=0;i<m*4+3;i++)
			cout<<"*";
		cout<<endl;
		memset(format,' ',sizeof(format));
		p=0;q=0;
		for (i=0;i<4*m-3;i++) 
		{
			if(i%4==0)
			{
				qislian=false;
				for (j=0;j<4*m+1;j++)
				{
						if(j%4==0) format[i][j]='H';
						else if((j-2)%4==0) 
						{
							format[i][j]='O';
							if(ASM[p][q]==1) 
							{
								format[i][j-1]='-';format[i][j+1]='-';
								qislian=true;
							}
							else if(ASM[p][q]==-1)
							{
								format[i-1][j]='|';format[i+1][j]='|';
								format[i-2][j]='H';format[i+2][j]='H';
								qislian=false;
							}
							else
							{
								if(qislian)
								{format[i][j+1]='-';qislian=true;}
								else
								{format[i][j-1]='-';qislian=false;} 
								if(i-2>=0&&format[i-2][j]==' ') {format[i-1][j]='|';format[i-2][j]='H';}
								else {format[i+1][j]='|';format[i+2][j]='H';}
							}
							q++;
						}
				}
				p++;
				q=0;
			}
		}
		for (i=0;i<4*m-3;i++) 
		{
			cout<<"*";
			for (j=0;j<4*m+1;j++)
			{
				cout<<format[i][j];
			}
			cout<<"*"<<endl;
		}
		for (i=0;i<m*4+3;i++)
			cout<<"*";
		cout<<endl;
	}
	return 0;
}
 

