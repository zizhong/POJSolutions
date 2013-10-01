#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double n, p, b;
    long floor,ceil;
    while(scanf("%lf", &n) == 1 && n) {
        if(n > 0) {
            for(p  = 32; p >= 1; p--) {
                b = pow(n, 1.0/p); 
                floor = b;
                ceil = b+1;
                if(b-floor <= 1e-12 || ceil-b <= 1e-12)
                    break;
            }
            printf("%.0lf\n", p);
        }
        else {
            n=-n;
            for(p = 31; p >= 1; p -= 2) {
                b = pow(n, 1.0/p); 
                floor = b;
                ceil = b+1;
                if(b-floor <= 1e-12 || ceil-b <= 1e-12)
                    break;
            }
            printf("%.0lf\n", p);
        }
    }
    return 0;
}
