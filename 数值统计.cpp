#include<stdio.h>
int main()
{
    float a,b,c,d;
    int i,t;
    a=b=c=0;
    int shuzu[1000];
    while (scanf("%d",&t)!=0)
    {
        if(t==0)break;
            a=b=c=0;
    		for(i=0;i<t;i++)
            {
                scanf("%f",&shuzu[i]);
                if(shuzu[i]>0)a++;
                if(shuzu[i]==0)b++;
                if(shuzu[i]<0)c++;
            }
		printf("%.f %.f %.f\n",c,b,a);
	}
	return 0;
}
