//#include<conio.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{   
    double x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    double a[1000][2];
    bool f=false;
    double x,y;
    while(cin>>x>>y)
    {      
           if(!f)
           {
           double m=(x-x2)*(x-x2)+(y-y2)*(y-y2);
           double n=(x-x1)*(x-x1)+(y-y1)*(y-y1);
           
            if(m-4*n>1e-6)
           {
               printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",x,y);
return 0;
               f=true;
               
           } 
           }        
    }
    if(!f)cout<<"The gopher cannot escape."<<endl;
    
    getchar();
    return 0;
} 




