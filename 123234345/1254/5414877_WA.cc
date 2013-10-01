#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
const double PI=3.14159265;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        double x1,y1,arc1,x2,y2,arc2;
        double k1,k2,a,b;
        cin>>x1>>y1>>arc1;
        cin>>x2>>y2>>arc2;
        k1 = tan((450 - arc1)*PI/180);
        k2 = tan((450 - arc2)*PI/180);

        a = (k1*x1 - k2*x2 - y1 + y2)/(k1 - k2);
        b = (k1*k2*(x1 - x2) + k1*y2 - k2*y1)/(k1 - k2);
        cout << fixed << setprecision(4)<<a<<" "<<b<<endl;
    }
}
