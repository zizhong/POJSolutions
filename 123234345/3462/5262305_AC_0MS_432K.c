#include<stdio.h>

#include<stdlib.h>



struct A{

    double start;

    double end;

};



int compare(const void*a,const void*b){

    return ((struct A*)a)->start-((struct A*)b)->start>0?1:-1;

}



int main()

{

    struct A segs[100];

    int test,n,a,b,x1,y1,x2,y2,i,j,result;

    double t,end;



    scanf("%d",&test);

    while(test--){

        scanf("%d",&n);

        scanf("%d%d",&a,&b);

        result=1;

        

        for(i=0;i<n;++i){

            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

            segs[i].start=(double)(b*x1-a*y1)/(b-y1);

            segs[i].end=(double)(b*x2-a*y2)/(b-y2);

            if(segs[i].start>segs[i].end){

                t=segs[i].start;

                segs[i].start=segs[i].end;

                segs[i].end=t;

            }

        }

        qsort(segs,n,sizeof(segs[0]),compare);

        end=-99999;

        for(i=0;i<n;i++){

            if(segs[i].start>end)

                result++;

            if(segs[i].end>end)

                end=segs[i].end;

        }

        printf("%d\n",result);

    }

    return 0;

}

