#include<iostream>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string s1,s2;
    char code;
    int d;
    int num=0;
    while(1)
    {
        cin>>s1;
        if(s1[0]=='0')
        {
             cout<<num<<endl;
             num=0;    
        }
        else if(s1[0]=='#')
            return 0;
        else
        {
            cin>>s2>>d>>code;
           // cout<<s1<<' '<<s2<<' '<<d<<' '<<code<<endl;
            switch (code)
            {
                   case 'B':
                        if(d%2) num+=d+d/2+1;
                        else num+=d+d/2;
                        break;
                   case 'Y':
                        if(d<500) d=500;
                        num+=d;
                        break;
                   case 'F':
                        num+=2*d;
                        break;
            }
        }
    }
}
