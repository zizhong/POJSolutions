#include <stdio.h>
#include <stdlib.h>
int cmp(const int *a,const int *b)
{
    return *(int *)a-*(int *)b;
}
int N, incr[2][2000], A[2000], V[2000], result;
inline int absv(int x) { return (x >= 0) ? x : -x; }
void go() {
    qsort(V,N,sizeof(int),cmp);
    int i, j, swi = 0;    
    for(i=0; i<N; i++) incr[swi][i] = (A[0] <= V[i]) ? 0 : A[0]-V[i];    
    for(i=1; i<N; i++)
    {
        swi = 1-swi;
        incr[swi][0] = incr[1-swi][0] + absv(A[i]-V[0]);        
        for(j=1; j<N; j++)
            incr[swi][j] = min(incr[swi][j-1], incr[1-swi][j] + absv(A[i]-V[j]));
    }
    
    for(i=0; i<N; i++)
        result = min(result, incr[swi][i]);
}
int main()
{
    
    scanf("%d\n", &N);    
    result = 1000000000;
    int i;    
    for(i=0;i<N;i++) {scanf("%d\n",&A[i]);V[i]=A[i];}
    go();        
    for(i=0;i<N;i++) {A[i]*=-1;V[i]*=-1;}
    go();    
    printf("%d\n",result);
}

