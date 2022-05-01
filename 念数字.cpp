#include<stdio.h>
int leng(int a)
{
    int flag = 0;
    while(a)
    {
        a /= 10;
        flag++;
    }
    return flag;
}
int main()
{
    int a;
    scanf("%d", &a);
    int i, temp, leng1, leng2, j, k;
    leng1 = leng2 = leng(a);
    if(a < 0)
    {
        printf("fu ");
        a = (-a);
    }
    if(a == 0)printf("ling"); //注意a为0时的情况
    for(i = 0; i < leng1; i++)
    {
        temp = 1;
        for(j = 0; j < leng2 - 1; j++)
        {
            temp = temp * 10;
        }
        leng2--;
        k = (a / temp);
        if(a != 0) a -= (temp * k);
        switch(k)
        {
        case 1:
            printf("yi");
            break;
        case 2:
            printf("er");
            break;
        case 3:
            printf("san");
            break;
        case 4:
            printf("si");
            break;
        case 5:
            printf("wu");
            break;
        case 6:
            printf("liu");
            break;
        case 7:
            printf("qi");
            break;
        case 8:
            printf("ba");
            break;
        case 9:
            printf("jiu");
            break;
        case 0:
            printf("ling");
            break;
        }
        if(leng2)printf(" ");
        else;
    }
    printf("\n");
    return 0;
}
