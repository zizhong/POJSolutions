#include <stdio.h>
int main()
{
	long input,i,save;
	scanf("%ld",&input);
	while(input!=0){
		if(input==1)printf("0\n");
		else {
			save=input;
			if(input%2==0)save/=2;
			while(input%2==0)input/=2;
			for(i=3;input!=1;i=i+2)
            {
				if(input%i==0)
                     save=(save/i)*(i-1);
				while(input%i==0)
                     input/=i;
			}
			printf("%ld\n",save);
		}
		scanf("%ld",&input);
	}
}

