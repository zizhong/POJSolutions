#include <stdio.h>

#include <stdlib.h>

#include <math.h>

 

int main(int argc, char *argv[])

{

    double n, m;

 

    while (scanf("%lf %lf", &m, &n) != EOF)

          printf("%.0f\n", exp(log(n)/m));   

}