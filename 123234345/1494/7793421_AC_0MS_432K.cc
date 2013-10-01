#include <stdio.h>
#include <math.h>

float r = 3950;
float R = 432000;
float D = 92900000;
float pi;
float L, theta1, theta2, beta1, beta;
float d;
float Gamma;
float fraction;

float degree ( float a )
{
 return a * 180.0 / pi;
}

float betaT ( float t )
{
 return beta1 - 2 * pi * t / 24.0 / 3600.0;
}

int main()
{

 float t;
 pi = 4 * atan(1);
 L = sqrt ( D*D + R*R - r*r );
 theta1 = atan ( R / D );
 theta2 = atan ( L / r );
 beta1 = theta1 + theta2;


 while ( 1 )
 {
  if ( scanf("%f", &t) == EOF ) break;
  beta = betaT(t);
  d = (D * cos ( beta ) - r ) / sin ( beta );
  if ( d <= -R )
    Gamma = - pi / 2;
  else if ( (d > -R ) && ( d < R) )
    Gamma = asin ( d / R );
  else
    Gamma = pi / 2;
  fraction = 0.5 + Gamma/pi + d * cos ( Gamma ) / pi / R;

  printf("%f\n", fraction);

 }
 return 0;
}


