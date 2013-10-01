#include"string.h"
#include"stdio.h"
#include"math.h"
#define cw 4.19
#define ci 2.09
#define temp 335
int main()
{ double mw,mi,tw,ti; 
 while(scanf("%lf%lf%lf%lf",&mw,&mi,&tw,&ti),mw||mi||tw||ti)
 {
    if((mw*cw*tw)>((-mi*ci*ti)+temp*mi))
         printf("0.0 g of ice and %.1f g of water at %.1f C\n",(mw+mi),
                           ((mw*cw*tw+mi*ci*ti-temp*mi)/(mw*cw+mi*cw)));
  else if((-mi*ci*ti)<(mw*cw*tw+mw*temp))
             { 
              if(mw*cw*tw>(-mi*ci*ti))  
                printf("%.1f g of ice and %.1f g of water at 0.0 C\n",(mi-(mw*cw*tw+mi*ci*ti)/335),(mw+(mw*cw*tw+mi*ci*ti)/335));
                else  printf("%.1f g of ice and %.1f g of water at 0.0 C\n",(mi+(-mw*cw*tw-mi*ci*ti)/335),(mw-(-mw*cw*tw-mi*ci*ti)/335));                }  
       else printf("%.1f g of ice and 0.0 g of water at %.1f C\n",(mw+mi),
                           ((mw*cw*tw+mw*temp+mi*ci*ti)/(mi*ci+mw*ci)));

   }
}