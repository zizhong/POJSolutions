 #include <cstdio> 
 #include <cstdlib> 
 #include <cstring>  
 int a[2001],c[2001]; 
 int f[2001][2001]; 
 int n; 
 #define min(x,y) ( (x)<(y)?(x):(y) ) 
 int cmp( const void *a , const void *b ) 
 { 
     return *((int *)a) - *((int *)b); 
 } 
 int main() 
 { 
     int i,j,k;     
     for( scanf("%d",&n) , i=0 ; i < n ; i++ ) scanf("%d",&a[i]) , c[i] = a[i]; 
     qsort( c , n , sizeof(int) , cmp ); //先排序 由小到大 
     for( i=n-1;i>=0;i-- ){ 
         for( j=n-1;j>=0;j-- ){     
             if( i+1==n ){ 
                 f[i][j] = abs( a[i] - c[j] ); 
             }
             else
             { 
                 if( j+1 == n ) 
                     f[i][j] = f[i+1][j] + abs( a[i] - c[j] ); 
                else 
                     f[i][j] = min( f[i+1][j]+abs(a[i]-c[j]) , f[i+1][j+1]+abs(a[i]-c[j]) );                     
             } 
         } 
         for( j=n-1;j>=1;j--){
             f[i][j-1] = min( f[i][j-1] , f[i][j] ); 
         } 
     } 
     printf("%d\n",f[0][0]);   } 
