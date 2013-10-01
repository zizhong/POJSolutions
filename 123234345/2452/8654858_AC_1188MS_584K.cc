#include<stdio.h>

const int N = 50010 ;
int   n , a[N] ;   
int main()
{
      while(scanf("%d",&n)!=EOF)
      {
      for(int i=1;i<=n;i++)
          scanf("%d",&a[i]);   
      int j , ans = -1 , max ; 
      for(int i=1;i<n;i++)
      {
          if(a[i]<a[i+1])
          {
               max = i ; 
               j = i ++ ;
               while(a[i]>a[j])
               {
                     if(a[i]>a[max])
                           max = i ;
                     i ++ ;          
               } 
               if(max-j>ans) ans = max - j ;      
               i = max  ; 
          }     
      }     
      printf("%d\n",ans);
     }
}
