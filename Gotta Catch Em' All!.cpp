#include<stdio.h>
#include<string.h>
int main()
{
	char a[100010];
	int i,min;
	int s[7]={0,0,0,0,0,0,0};
	scanf("%s",a);
	getchar();
	for(i=0;i<strlen(a);i++)
	{
	    switch(a[i])
	    {
	        case 'B':s[0]+=1;break;
	        case 'u':s[1]+=1;break;
	        case 'l':s[2]+=1;break;
	        case 'b':s[3]+=1;break;
	        case 'a':s[4]+=1;break;
	        case 's':s[5]+=1;break;
	        case 'r':s[6]+=1;break;
	        default:break;
	    }
	}
	s[1]=s[1]/2;
	s[4]=s[4]/2;
	min=s[0];
	for(i=0;i<7;i++)
	{
        if(s[i]<min)
            min=s[i];
        else;
	}
	printf("%d",min);
	return 0;
 }
