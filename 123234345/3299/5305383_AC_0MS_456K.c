#include <stdio.h>
#include <math.h>

int main()
{
	float temperature,dewpoint,humidex;
	float h,e,f1,f2;
	char c1,c2;
	while(scanf("%c",&c1),c1!='E')
	{	
		scanf("%f %c %f",&f1,&c2,&f2);
		switch (c1+c2)
		{
		case 'T'+'D':
			{
				temperature = (c1=='T') ? f1:f2;
				dewpoint = (c1=='D') ? f1:f2;
				e = (float) (6.11 * exp (5417.7530 * ((1/273.16) - (1/(dewpoint+273.16)))));
				h = (float) ((0.5555) * (e - 10.0));
				humidex = temperature + h;
				break;
			}
		case 'T'+'H':
			{
				temperature = c1=='T' ? f1:f2;
				humidex = (c1=='H') ? f1:f2;
				h = humidex - temperature;
				e = (float) (h / 0.5555 + 10.0) ;
				dewpoint = (float) (1/(-log(e/6.11)/5417.7530 + (1/273.16))-273.16);
				break;
			}

		case 'H'+'D':
			{
				humidex = (c1=='H') ? f1:f2;
				dewpoint = (c1=='D') ? f1:f2;
				e = (float) (6.11 * exp (5417.7530 * ((1/273.16) - (1/(dewpoint+273.16)))));
				h = (float) ((0.5555) * (e - 10.0));
				temperature = humidex - h;
				break;
			}
		}
		printf("T %.1f D %.1f H %.1f\n",temperature,dewpoint,humidex);
		//scanf("%c",&c1);
		getchar();
	}
	return 0;
}
